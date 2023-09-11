#!/bin/bash

#renk kodları tanımlandı
red='\033[1;31m'
green='\033[1;32m'
yellow='\033[1;33m'
blue='\033[1;34m'
light_cyan='\033[1;96m'
reset='\033[0m'

#kullanıcı kontrolleri tanımlandı
if [[ "`whoami`" != "root" ]] ; then

    printf "${blue}Host: `hostname`\n"
    printf "Kullanıcı: `whoami`\n"
    printf "Shell: ${SHELL}\n"
    printf "Tarih: `date`\n"
    printf "\nWelcome `whoami` ${reset}\n"

elif [[ "`whoami`" = "root" ]] ; then
    while :
    do
    	printf "${red}ROOT user algılandı ROOT terminalden çıkınız!!!${reset}\n"
    	trap 'printf "${red}ROOT user algılandı ROOT terminalden çıkınız!!!${reset}\n"' INT
	    trap 'printf "${red}ROOT user algılandı ROOT terminalden çıkınız!!!${reset}\n"' TSTP
        sleep 3
        
    done  
fi
