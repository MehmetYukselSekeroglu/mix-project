import luhn
import random
import time
import sys

# Basit bir random kart üretici 
# https://t.me/BayTapsan tarafından yazılmıştır 
# GNU GPL V3 ile lisanslanmıştır 


""" 
Üretilen kartlar luhn ve diğer otomatik sistemlerden geçer 
herhangi bir insana ait değildir veya zarar verme amaçlı değildir 
bu modül eğitim amaçlıdır.
""" 



# Kartları üreten basit ana fonksiyon
def RandCard(target_bin) -> str: 
    target_bin = str(target_bin)
    
    RandNumber = random.randint(100000000, 999999999)
    RandNumber = f"{target_bin}{RandNumber}"
    verfy = luhn.generate(str(RandNumber))
    RandCard_is = f"{RandNumber}{verfy}"
    RandCvv = random.randint(110, 998)
    RandExDate_mounth = random.randint(1, 12)
    if RandExDate_mounth < 10:
        RandExDate_mounth = f"0{RandExDate_mounth}"
    a = time.localtime()

    a = a[0]
    a = int(a) + 1
    b = a + 8
    RandExDate_years = random.randint(a, b)
    RandExDate_years = str(RandExDate_years)
    Date = f"{RandExDate_mounth}|20{RandExDate_years[2]}{RandExDate_years[3]}|"

    return f"{RandCard_is}|{Date}{RandCvv}" 



# Herhangi bir sistemde api olarak kullanılması için arayüz 
def card_generator_api(target_bin, gen_pcs:int) -> list[str]:

    
    if not target_bin.isnumeric():
        return [ "false", "[ - ] Hata: Bin formatı geçersizdir, işlem iptal edildi." ]
    
    if len(target_bin) != 6:
        return [ "false", "[ - ] Hata: Bin numarası 6 haneli olmalıdır." ]
    
    data_array = []
    for _ in range(0, gen_pcs):
        data_array.append(RandCard(target_bin=target_bin))
    
    
    return [ "true", data_array ]
    
    
    
    
if __name__ == "__main__":
    need_bin = str(input("Enter Your Bin: "))
    data_results = card_generator_api(target_bin=need_bin, gen_pcs=6)
    
    if data_results[0] != "true":
        print(data_results[1])
        sys.exit(1)
    
    data_results = data_results[1]
    
    print(f">> Kartlar:")
    for element in data_results:
        print(element)
