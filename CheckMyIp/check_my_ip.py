#!/usr/bin/env python3 




import requests
import sys


# COLOR CODES

siyah = "\033[30m"
kirmizi = "\033[31m"
yeşil = "\033[32m"
sari= "\033[33m"
mavi = "\033[34m"
mor = "\033[35m"
turkuaz = "\033[36m"
beyaz = "\033[37m"

# BOLD TYPE CODES

normal = "\033[0m"
kalin = "\033[1m"



def INFO_OUT(target_msg:str) -> None:
    template = f"{kalin}{beyaz}[ {mavi}INFO{beyaz} ]{normal}: {target_msg}"
    print(template)

def ERR_OUT(target_msg:str) -> None:
    template = f"{kalin}{beyaz}[ {kirmizi}ERROR{beyaz} ]{normal}: {target_msg}"
    print(template)

def WARN_OUT(target_msg:str) -> None:
    template = f"{kalin}{beyaz}[ {turkuaz}WARNING{beyaz} ]{normal}: {target_msg}"
    print(template)


def STD_LOG_OUT(target_msg:str) -> None:
    template = f"{kalin}{beyaz}[ LOG ]{normal}: {target_msg}"
    print(template)





TARGET_URL = "https://ipinfo.io/myip"
HEADERS = { "User-Agent": 
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.183 Safari/537.36 OPR/72.0.3815.320"
}




try:
    INFO_OUT(f"Checking your public ip addrs pls wait...")
    req = requests.get(url=TARGET_URL)
    
    if req.status_code != 200:
        ERR_OUT(f"Request failed. Status code: {req.status_code}")
        sys.exit(1)
        
    req = req.json()
    for element_key in req.keys():
        if element_key == "readme":
            continue
        print(f"{kalin}{mavi}::: {element_key} :::{normal}{yeşil} {req[element_key]}{normal}{beyaz} ")

    INFO_OUT(f"Proccess successful.")
    sys.exit(1)
    
except Exception as err:
    ERR_OUT(f"{err}.")
    sys.exit(1)