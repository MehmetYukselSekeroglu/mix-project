<?php

header("Content-Type: application/json; utf-8;");

$hostname_is="localhost";
$db_username="root";
$db_passowrd="";
$db_name="cc_bins";

$developed_by="illegalXdark";


$link = new mysqli($hostname_is,  $db_username, $db_passowrd, $db_name);

ini_set("display_errors", 0);
error_reporting(0);


if (isset($_GET)) {
    $target_bin = htmlspecialchars($_GET["bin"]);

    //

    //
    $sql = "";

	    
    if (isset($_GET["key"]) && in_array($_GET["key"], $all_key) ){
    	$key_verify = 1;
    }else{
   	 echo json_encode(["success" => "false", "message" => "api key error" , "by" => $developed_by]);
    	die();
    }

	if (!empty($target_bin)) {
        $sql = "SELECT * FROM $db_name WHERE bin_number=?";
        $result = $link->prepare($sql);
        $result->bind_param("s", $target_bin);
        $result->execute();
        $result = $result->get_result();

	else {
            echo json_encode(["success" => "false", "message" => "param error","by"=>$developed_by]);
            die();
        }

    if (!$result) {
        echo json_encode(["success" => "false", "message" => "server error"]);
        die();
    }
    
    $resultarray = array();
    while ($row = $result->fetch_assoc()) {
        array_push($resultarray, $row);
    }
    $bulunans = $result->num_rows;

    if ($bulunans < 1) {
        echo json_encode(["success" => "false", "message" => "not found", "by" => $developed_by  ]);
        die();
    }

		echo json_encode(["success" => "true", "number" => $bulunans, "by" => $developed_by ,"data" => $resultarray]);
		die();
	} else {
    echo json_encode(["success" => "false", "message" => "request error"]);
    die();

}


?>
