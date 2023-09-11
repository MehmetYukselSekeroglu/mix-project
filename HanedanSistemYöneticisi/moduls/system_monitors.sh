#!/bin/bash


#colors 
red='\033[1;31m'
green='\033[1;32m'
yellow='\033[1;33m'
blue='\033[1;34m'
light_cyan='\033[1;96m'
reset='\033[0m'


#command paths
#standart kullanıcılar için olan komutların path ları
COMMAND_PATH_1="/bin"
COMMAND_PATH_2="/usr/bin"
COMMAND_PATH_3="/usr/share/bin"


#root yetkisi gerektiren komutların path ları
ADMIN_COMMAND_PATH_1="/sbin"
ADMIN_COMMAND_PATH_2="/usr/sbin"
ADMIN_COMMAND_PATH_3="/usr/local/sbin"

function COMMAND_CONTROL(){

	searchto="$1"

	if [[ -e "$COMMAND_PATH_1/$searchto" || -e "$COMMAND_PATH_2/$searchto" || -e "$COMMAND_PATH_3/$searchto" || -e "$ADMIN_COMMAND_PATH_1/$searchto" || -e "$ADMIN_COMMAND_PATH_2/$searchto" || -e "$ADMIN_COMMAND_PATH_3/$searchto" ]] ; then
		command_status=${yellow}"OK"${reset}
		printf "${blue}Command $searchto status -> $command_status ${reset}\n"
	else 
		command_status=${red}"NOT-OK"$reset
		printf "${blue}Command $searchto status -> $command_status ${reset}\n"
	fi 
}

function COMMAND_CONFIRM(){

	searchto="$1"

	if [[ -e "$COMMAND_PATH_1/$searchto" || -e "$COMMAND_PATH_2/$searchto" || -e "$COMMAND_PATH_3/$searchto" || -e "$ADMIN_COMMAND_PATH_1/$searchto" || -e "$ADMIN_COMMAND_PATH_2/$searchto" || -e "$ADMIN_COMMAND_PATH_3/$searchto" ]] ; then
		command_confirm="1"
	else 
		command_confirm="0"
	fi 
}


COMMAND_CONFIRM apt 
if [[ "$command_confirm" = "1" ]] ; then
	function installer_func(){
		sudo apt-get install $1
	}
fi







function main_printer(){
	printf """${green}Hostname: ${blue}`hostname`${resets} 
${green}User: ${blue}`whoami`${reset}
${green}OS: ${blue}`uname -o`${reset}
${green}Kernel release: ${blue}`uname -r`${reset}
${green}Processor type: ${blue}`uname -p`${reset}
	\n"""

}

function package_status(){
	COMMAND_CONTROL python3
	COMMAND_CONTROL pip3
	COMMAND_CONTROL wireshark
	COMMAND_CONTROL netsniff-ng
	COMMAND_CONTROL aircrack-ng 
	COMMAND_CONTROL sudo 
	COMMAND_CONTROL ifconfig
	COMMAND_CONTROL zsh
	COMMAND_CONTROL g++
	COMMAND_CONTROL gcc
	
}


function debian_standart(){
	printf "${blue}PRIME system monitor.....\n${reset}"

}

debian_standart
main_printer 
package_status
