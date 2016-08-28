<?php

function start() {
	settype($vars,"array");


	$r = getenv("SERVER_SOFTWARE");
	preg_match("/\d+\.\d+\.\d+/",$r,$p);
	$vars["cnt_de"] = '

<div align="center"><img src="images/mowesportable.gif" alt="" width="300" height="95" border="0"></div>

<br><br>

<div style="font-weight:bold; color: green">Apache '.$p[0].' läuft</div>
<div style="font-weight:bold; color: green">PHP '.phpversion().' funktioniert</div>';


$vars["cnt_en"] = '

<div align="center"><img src="images/mowesportable.gif" alt="" width="300" height="95" border="0"></div>

<br><br>
<div style="font-weight:bold; color: green">Apache '.$p[0].' is running</div>
<div style="font-weight:bold; color: green">PHP '.phpversion().' works</div>';


	if(@mysql_connect("localhost","root","")) {

		$db = mysql_connect("localhost","root");
		$res = mysql_query("SELECT VERSION();");
		$res = mysql_fetch_array($res);
		mysql_close($db);
		$vars["cnt_de"].= '<div style="font-weight:bold; color: green">MySql '.$res[0].' funktioniert</div>';
		$vars["cnt_en"].= '<div style="font-weight:bold; color: green">MySql '.$res[0].' is running</div>';
	}else {
		$vars["cnt_de"].= '<div style="font-weight:bold; color: red">MySql funktioniert nicht</div>';
		$vars["cnt_en"].= '<div style="font-weight:bold; color: red">MySql is not running</div>';
	}


	$d = getenv("DOCUMENT_ROOT");
	$d = explode("/",$d);
	array_pop($d);
	$d = implode("/",$d);
	$d.="/ImageMagick/identify.exe";
	$d = str_replace("/","\\",$d);
	if(is_file($d)) {
		exec($d,$ret);
		$ret = implode("",$ret);
		unset($p);
		preg_match("/\d+\.\d+\.\d+/",$ret,$p);
		$vars["cnt_de"].= '<div style="font-weight:bold; color: green">ImageMagick '.$p[0].' ist vorhanden und funktioniert</div>';
		$vars["cnt_en"].= '<div style="font-weight:bold; color: green">ImageMagick '.$p[0].' is available and works</div>';
	}
	$vars["cnt_de"].= '<br><div>Document Root ist: '.getenv("DOCUMENT_ROOT").'</div>';
	$vars["cnt_en"].= '<br><div>Document Root is: '.getenv("DOCUMENT_ROOT").'</div>';
	$vars["titel_de"] = "Willkommen";
	$vars["titel_en"] = "Welcome";
	$vars["image"] = "mowes.jpg";




	$vars["cnt_de"].="<br><fieldset><legend>Installierte Pakete</legend><ul>";
	$vars["cnt_en"].="<br><fieldset><legend>Installed packages</legend><ul>";

	$cnt = file_get_contents("../../mowes/packages.ini");
	$cnt = preg_split("/\[(.)*\]/",$cnt);

	foreach ($cnt as $value) {
		if(trim($value) != "") {

			$lines = explode("\n",trim($value));

			$data = convert_to_assoc($lines);
				if($data["software_type"] == "server") {
					$vars["cnt_de"].="<li>".$data["package_name"] . " (Version ".$data["package_version"].")</li>";
					$vars["cnt_en"].="<li>".$data["package_name"] . " (Version ".$data["package_version"].")</li>";
				}else{

					if($_SERVER['SERVER_PORT'] != 80) {

					$vars["cnt_de"].='<li><a href="http://'.$_SERVER['SERVER_ADDR'].':'.$_SERVER['SERVER_PORT'].'/'.$data["install_dir"].'">'.$data["package_name"] . '</a> (Version '.$data["package_version"].')</li>';
                    $vars["cnt_en"].='<li><a href="http://'.$_SERVER['SERVER_ADDR'].':'.$_SERVER['SERVER_PORT'].'/'.$data["install_dir"].'">'.$data["package_name"] . '</a> (Version '.$data["package_version"].')</li>';

					}else{

					$vars["cnt_de"].='<li><a href="http://'.$_SERVER['SERVER_ADDR'].'/'.$data["install_dir"].'">'.$data["package_name"] . '</a> (Version '.$data["package_version"].')</li>';
                    $vars["cnt_en"].='<li><a href="http://'.$_SERVER['SERVER_ADDR'].'/'.$data["install_dir"].'">'.$data["package_name"] . '</a> (Version '.$data["package_version"].')</li>';
					}
				}




		}
	}

	$vars["cnt_en"].="</ul></fieldset>";









	$c = 0;

	$vars["links"][$c]["text_de"] = "Hinweise";
	$vars["links"][$c]["text_en"] = "Informations";
	$vars["links"][$c]["link"] = "index.php?p=readme&lang=".$_GET['lang'];
	$c++;

	$vars["links"][$c]["text_de"] = "Bedingungen";
	$vars["links"][$c]["text_en"] = "Conditions";
	$vars["links"][$c]["link"] = "index.php?p=conditions&lang=".$_GET['lang'];
	$c++;

	$vars["links"][$c]["text_de"] = "phpinfo";
	$vars["links"][$c]["text_en"] = "phpinfo";
	$vars["links"][$c]["link"] = "phpinfo.php";
	$c++;

	$vars["links"][$c]["text_de"] = "MoWeS Wiki";
	$vars["links"][$c]["text_en"] = "MoWeS Wiki";
	$vars["links"][$c]["link"] = "http://www.moweswiki.chsoftware.net";
	$c++;

	$vars["links"][$c]["text_de"] = "MoWeS Forum";
	$vars["links"][$c]["text_en"] = "MoWeS Forum";
	$vars["links"][$c]["link"] = "http://www.mowesforum.chsoftware.net";
	$c++;

	$vars["links"][$c]["text_de"] = "MoWeS Help";
	$vars["links"][$c]["text_en"] = "MoWeS Help";
	$vars["links"][$c]["link"] = "http://www.moweshelp.chsoftware.net";
	$c++;


	$vars["links"][$c]["text_de"] = "Kontakt";
	$vars["links"][$c]["text_en"] = "Contact";
	$vars["links"][$c]["link"] = "http://www.chsoftware.net/".$_GET['lang']."/contact/contact.htm";
	$c++;


	return $vars;

}

function convert_to_assoc($data) {
	settype($ret,"array");
	foreach ($data as $value) {
		if(trim($value)!="") {
			$pos = strpos($value,"=");
			$key = trim(substr($value,0,$pos));
			$val = trim(substr($value,$pos+1));
			$ret[$key] = $val;
		}
	}

	return $ret;
}

?>