#!/usr/bin/env python3 

#BY PRIME 
def check_dns():
    with open("/etc/resolv.conf","r") as dns_file:
        dns_stat = dns_file.readlines()
        print("-DNS info:")
        b=0
        for i in dns_stat:
            if "#" not in i:
                b+=1
                print(f"DNS{b}: {i}",end="")

check_dns()
