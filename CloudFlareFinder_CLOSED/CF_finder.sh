#!/usr/bin/env bash
cat /dev/null > resutl.txt 
cat /dev/null > ip.txt


if [[ "$1" = "-h" || "$1" = "--help" ]];then
    echo "Kullanım: "
    echo "bash $0 denenecek-domain.com"
    exit 
fi
echo "| By ONLY v1.0            |"
echo "Thanks IP-tracer"
echo "---------------------------" 
echo "sorgulanacak DNS adeti"
wc -l dns_list.txt 
echo "|-------------------------|"
echo "|DNS istekleri yapılıyor..|"
echo "|-------------------------|"
sleep 1

while read line 
do 
    dig $1 @$line -4 | sed  '/;/d' |cut -f 6 | sed '/N/d' 1>> resutl.txt  
    echo "istek yapulan DNS: $line "
done < dns_list.txt
echo "|-----------------------------------------------------|"
echo "|DNS istekleri tamamlandı ip adresleri kontrol edilcek|"
echo "|-----------------------------------------------------|"
sort resutl.txt | uniq > ip.txt
sleep 1
while read ip
do 
    php traceip.php $ip  
    if [[ "$?" != "0"  ]];then
        exit # ilk eşleşmede işlem sonlanmasın derseniz burayı yoruma alon ve alt satırın yorumunu silin
        #printf "1" > /dev/null
    fi
done < ip.txt

