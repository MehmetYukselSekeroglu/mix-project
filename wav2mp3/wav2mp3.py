#!/usr/bin/env python3
import argparse
import os 
from pydub import AudioSegment
import sys

"""
    
    03.09.2023 SIGNT Türk VAW2MP3 
    SDR yazılımları ile kadedilen sesleri mp3 e dömüştürmek için basit bir betik 



"""





print(f"\n>> Powered By SIGNT Türk\n\n")

parser = argparse.ArgumentParser()
parser.add_argument("-i",required=True,help="path of input file")
parser.add_argument("-o",required=True, help="output filename")

args_is = vars(parser.parse_args())



target_file = args_is["i"]
output_name = args_is["o"]

# SES DEN METNE FONKSIYONUNDA GOOGLE API ICIN * FORMATDAN VAW FORMATINA CEVIRME FONKSIYONIU 
def ConvertAnyAudio_to_wav(target_file_path:str, output_names:str):
    """ Desteklenen formatlardaki ses dosyalarını vaw foarmatına dönüştütüt
        Desteklenen formatlar -> "MP3","OGG","FLAC","AAC","AIFF","WMA","WAV"

    Args:
        target_file_path (str): hedef dosyanın dosya yolu 
        temp_dir_path (str, optional): final olarak oluşan *.vaw dosyasının kayıt konumu. Defaults to TEMP_DIR.

    Returns:
        dict: key: success -> true,false eğer urum başarılı ise success:true ve path döner değilse code:hata durumu
    """
    
    TARGET_FILE_FORMAT = "mp3"
    
    if not os.path.exists(target_file_path):
        return {"success":"false", "code":"invaid path"}
    
    target_file_extensions = target_file_path.split(".")
    target_file_extensions = target_file_extensions[len(target_file_extensions)-1]

    supported_formats = ["WAV","OGG","FLAC","AAC","AIFF","WMA","WAV"]
    
    if target_file_extensions.upper() not in supported_formats:
        return {"success":"false", "code":"not supported file extensions"}

    LoadedAudio = AudioSegment.from_file(target_file_path, format=target_file_extensions)
    export_name = output_names
    
    # dosyanın export edilmesi 
    LoadedAudio.export(export_name, format=TARGET_FILE_FORMAT)

    if os.path.exists(export_name):
        return {"success":"true", "path":str(export_name)}
    else:
        return { "success":"false", "code":"export error"}




print(f"[ INFO ]: Converting started")
data_is = ConvertAnyAudio_to_wav(target_file_path=target_file, output_names=output_name)


if data_is["success"] != "true":
    err_msg = data_is["code"]
    print(f"[ ERROR ]: {err_msg}")
    sys.exit(1)

path_is = data_is["path"]
print(f"[ INFO ]: Converting success: {path_is}")
sys.exit(0)
