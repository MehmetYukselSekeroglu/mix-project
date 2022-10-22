#!/usr/bin/env python3 
import os
import time 
#BY PRIME 


def check_dns():
    with open("/etc/resolv.conf","r") as dns_file:
        dns_stat = dns_file.readlines()
        print("-DNS info")
        b=0
        for i in dns_stat:
            if "#" not in i:
                b+=1
                print(f"DNS{b}: {i}",end="")

def check_os(): 
    if os.name == 'nt':
        os_support=False
    elif os.name == 'posix':
        os_support=True
    else:
        os_support=False
    return os_support

if check_os() == True:
    check_dns()
else:
    print("OS not supported! exiting...")
    time.sleep(1)
    exit()
