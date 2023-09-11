<?php
function trac($ip) {

$data = @unserialize(file_get_contents("http://ip-api.com/php/".$ip));
$FCL="\033[01;33m";
$MCL="\033[01;37m>\033[01;32m";
$NCL="\033[00m";
date_default_timezone_set($data['timezone']);

if(!empty($data['status']) && $data['status'] == 'success') {
  if (!empty($ip))
    if (!strstr($data['isp'],"Cloudflare")){  
      echo "#####################\n\n";
      echo "[+]Temiz ip! -> $ip\n\n";
      echo "#####################\n";
      exit(1);
    }else{
      echo "[-]CloudFlare Tespit Edildi: $ip\n";
    }
} else {
  echo "\n\033[01;31m Sorry unable to track your\033[01;33m IP Address\033[01;31m !!!\033[00m\n";
  echo "\033[01;31m Check your \033[01;33mNetwork connection\033[01;31m !!\033[00m\n";
  echo "\033[01;31m If you are \033[01;33mOnline\033[01;31m then check your \033[01;33mIP Address\033[01;31m !!\033[00m\n\n";
}
}
if (!empty($argv[1])){
  trac($argv[1]); 
}
?>
