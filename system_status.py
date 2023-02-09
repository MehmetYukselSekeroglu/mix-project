import psutil
from colorama import *

#1.073.741.824 

def DiskUsage(DiskPath):
    return psutil.disk_usage(DiskPath)


def BatteryStatus():
    RawData=psutil.sensors_battery()
    
    BattaryPower=RawData[0]
    BattaryPower = int(BattaryPower)

    PowerPlug= RawData[2]
    if PowerPlug:
        GüçDurum="Prize bağlı"
    else:
        GüçDurum="Pilde"
    return BattaryPower,GüçDurum,PowerPlug

def PrintBatteryStatus():
    color_red = Fore.RED
    color_blue = Fore.BLUE
    color_green = Fore.GREEN
    color_reset = Fore.RESET
    
    RawData=BatteryStatus()
    
    if int(RawData[0]) < 15:
        durum_metni = f"{color_red}KRİTİK{color_reset}"
    elif int(RawData[0]) == 100:
        durum_metni = f"{color_green}TAM DOLU{color_reset}"
    else:
        durum_metni = f"{color_blue}NORMAL{color_reset}"

    print(f"""
{color_blue}|{"-"*20}{color_reset}
{color_blue}| Pil Bilgisi: {color_reset}
{color_blue}|{"-"*20}{color_reset}
{color_blue}| Doluluk: {color_reset}%{RawData[0]} {durum_metni}
{color_blue}| Durum: {color_reset}{RawData[1]}
{color_blue}|{"-"*20}{color_reset}""")



def PrintDiskInformation():
    color_red = Fore.RED
    color_blue = Fore.BLUE
    color_green = Fore.GREEN
    color_reset = Fore.RESET

    PartionInfo = psutil.disk_partitions()

    #print(color_blue+"|"+"-"*20+color_reset)
    print(color_blue+"| Disk Bilgisi: ")

    for disk_list in PartionInfo:
        
        device_name = disk_list.device
        device_filesystem = disk_list.fstype
        device_mountpoibt = disk_list.mountpoint

        DolulukOranı = psutil.disk_usage(device_mountpoibt)       
        kullanım_tipi = disk_list.opts
        kullanım_tipi = f"{kullanım_tipi[0]}{kullanım_tipi[1]}"

        ToplamDiskBoyutu = DolulukOranı[0]
        KullanılanAlan = DolulukOranı[1]
        KullanılabilirKalanAlan = DolulukOranı[2]
        Control = DolulukOranı[3]
        if  Control == 90:
            Durum = f"{color_blue}!-BAKIM GEREK-!{color_reset}"
        elif Control < 90:
            Durum = f"{color_green}GUZEL{color_reset}"
        elif Control > 90:
            Durum = f"{color_red}!-KRİTİK-!{color_reset}"


        print(f"""{color_blue}|{"-"*20}{color_reset}
{color_blue}| Device:{color_reset} {device_name}
{color_blue}| FileSystem:{color_reset} {device_filesystem}
{color_blue}| MountPoint:{color_reset}{device_mountpoibt}
{color_blue}| Type:{color_reset} {kullanım_tipi}
{color_blue}| TamBoyut:{color_reset} {int(ToplamDiskBoyutu / 1048576,)} MB
{color_blue}| KullanılanAlan: {color_reset}{int(KullanılanAlan/1048576)} MB
{color_blue}| KullanılabilirAlan: {color_reset}{int(KullanılabilirKalanAlan/1048576)} MB
{color_blue}| KullanımOranı: {color_reset}%{DolulukOranı[3]} {Durum}""")
    print(color_blue+"|"+"-"*20+color_reset)


def DiskInformation():
    PartionInfo = psutil.disk_partitions()
    return PartionInfo




#1.073.741.824  -> 1 gb is x byte 

PrintBatteryStatus()
PrintDiskInformation()
