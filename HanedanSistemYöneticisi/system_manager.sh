#!/bin/bash

red='\033[1;31m'
green='\033[1;32m'
yellow='\033[1;33m'
blue='\033[1;34m'
light_cyan='\033[1;96m'
reset='\033[0m'


STANDART_DIR="/opt/user_control"
ROOT_LOCKER_PATH="$STANDART_DIR/root_control.sh"

#standart kullanıcılar için olan komutların path ları
COMMAND_PATH_1="/bin"
COMMAND_PATH_2="/usr/bin"
COMMAND_PATH_3="/usr/share/bin"


#root yetkisi gerektiren komutların path ları
ADMIN_COMMAND_PATH_1="/sbin"
ADMIN_COMMAND_PATH_2="/usr/sbin"
ADMIN_COMMAND_PATH_3="/usr/local/sbin"




function ROOT_TERM_CONTROL()
{

	if [[ ! -d "$STANDART_DIR" || ! -e "$ROOT_LOCKER_PATH" ]] ; then
		root_lock_stat="!Unlock!"
		status_colar=$red
	elif [[ -d "$STANDART_DIR" && -e "$ROOT_LOCKER_PATH" ]] ; then
		root_lock_stat="Lock"	
		status_colar=$green
	fi
	printf "Root konsol kilidi kontrol ediliyor -> ${status_colar}${root_lock_stat}${reset}\n"
}



function KERNEL_VERSION_CONTROL()
{
	KERNEL_VERSION_NOW="`uname -r`"
	printf "${blue}Kernel versiyonu kontrol ediliyor ->${yellow} ${KERNEL_VERSION_NOW}${reset}\n"

}

function ROOT_LOCKER()
{
	if [[ -e "$ROOT_LOCKER_PATH" ]] ; then
		printf "${green}Root terminal zaten kilitli!${reset}\n"
		sleep 1
			
	elif [[ ! -e "$ROOT_LOCKER_PATH" ]] ; then 
		printf "${blue}Root konsol kilitleniyor..!"
		sudo cp moduls/root_control.sh /opt/user_control/
		sleep 1	
		
		if [[ -e "/root/.bashrc" ]] ; then 
			echo "bash ${ROOT_LOCKER_PATH}" >> /root/.bashrc
		elif [[ -e "/root/.zshrc" ]] ; then
			echo "bash ${ROOT_LOCKER_PATH}" >> /root/.zshrc
		else 
			printf "${red}Desteklenen shell dosyası bulunamadı!${red}\n"
		fi 
		printf "${blue}Root terminal kilitlendi${reset}\n"
	fi	
}


function ISLEM_SECIM()
{
	printf "\n\n"
	printf "${blue}işlem seçiniz:\n"
	printf "1- Root konsolu kilitle\n"
	
	printf "99- Çıkış"
	printf "\n\n ${reset}"
	read -p "--> " SECIM

	if [[ "$SECIM" = "1" ]] ; then
		ROOT_LOCKER
	elif [[ "$SECIM" = "99" ]] ; then 
		break
	fi
}

function SETUP_CONTROL()
{
	if [[ ! -d "/opt/user_control" ]] ; then
		sudo mkdir /opt/user_control
	fi 

}

function FILE_SYSTEM_SHOW() #şuan gerek duyulmamaktadır 
{
	clear 
	sudo df -h 
	
	read -p "Devam etmek için ENTER"

}


function SYSTEM_MONIT(){
	clear 
	bash moduls/system_monitors.sh
	echo && echo 
	read -p "Devam etmek için ENTER"

}

function WEB_SITE_FILE_SCRAPER() #kullanılması planlanmayan bir modüldür bu
{
	clear 
	if [[ ! -e "$COMMAND_PATH_1/wget" && ! -e "$COMMAND_PATH_2/wget" && ! -e "$COMMAND_PATH_3/wget" ]] ; then
		if [[ -e "$COMMAND_PATH_1/apt" || -e "$COMMAND_PATH_2/apt" || -e "$COMMAND_PATH_3/apt"  ]] ; then
			printf "${green}installing wget...${reset}\n"
			sudo apt-get install -y wget 1> /dev/null
		fi 
	fi 
	while :
	do
		clear 
		printf "${blue}Web site url sini giriniz...\n\n"
		read -p "-->" WEB_SITE_URL
	
		clear 
	
		printf "${blue}indirilecek dosya tipi:\n"
		printf "1-png\n"
		printf "2-pdf\n"
		printf "${reset}"
		
		read -p "-->" SELECTION
		
		if [[ "$SELECTION" = "1" ]] ; then 
			INSTALL_FORMATS="png"
			wget -r -A $INSTALL_FORMATS $WEB_SITE_URL
			read -p "Devam etmek için ENTER"
			 
		elif [[ "$SECIM" = "2" ]] ; then
			INSTALL_FORMATS="pdf"
			wget -r -A $INSTALL_FORMATS $WEB_SITE_URL
			read -p "Devam etmek için ENTER"
		else 
			printf "${red}Bilinmeyen girdi...!${reset}"
			sleep 1
		fi 
	done 	
}

while :
do 
clear
	if [[ "$UID" != "0" ]] ; then
		printf "${red}Root izni gereklidir!\n"
		break
	fi
	#--------------------------------------------------------------#
	printf "${blue}Hanedan-ı Root sistem yönetim aracına hoş geldiniz\n\n"
	SETUP_CONTROL
	ROOT_TERM_CONTROL
	KERNEL_VERSION_CONTROL
	#--------------------------------------------------------------#
	printf "\n\n"
	printf "${blue}işlem seçiniz:\n"
	printf "1- Root konsolu kilitle\n"
	printf "2-Sistem monitörü\n\n"
	printf "99- Çıkış"
	printf "\n\n ${reset}"
	read -p "--> " SECIM

	if [[ "$SECIM" = "1" ]] ; then
		ROOT_LOCKER
	elif [[ "$SECIM" = "2" ]] ; then
		SYSTEM_MONIT
	elif [[ "$SECIM" = "99" ]] ; then 
		break
	else 
		printf "${red}Bilinmeyen girdi!${reset}\n"
		sleep 1 && clear
		
	fi
	
done 
