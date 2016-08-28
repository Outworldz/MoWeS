<?php

//check for libmysql.php

$doc_root = $_SERVER['DOCUMENT_ROOT'];
$mowes_root = str_replace('www','',$doc_root);
$mowes_root = str_replace('/','\\',$mowes_root);

$apache2_bin = $mowes_root . 'apache2\bin\\';
$php5 = $mowes_root . 'php5\\';

if(is_file($php5.'libmysql.dll') && !is_file($apache2_bin.'libmysql.dll')) {
	copy($php5.'libmysql.dll',$apache2_bin.'libmysql.dll');
	echo '<p>MoWeS had to install die MySQL Library in the Apache2 binary directory (Copied '.$php5.'libmysql.dll to '.$apache2_bin.'libmysql.dll). Please restart the server and reload this page. Thank you.<br>
			MoWeS hat die MySQL Bibliothek erfolgreich in das Binärverzeichnis von Apache2 kopiert ('.$php5.'libmysql.dll kopiert nach '.$apache2_bin.'libmysql.dll). Bitte starten Sie den Server neu und laden Sie danach diese Seite neu. Vielen Dank!
	</p>';
	die();
}





include("include.inc.php");

$query = getenv("QUERY_STRING");
parse_url($query);


if($_GET['p'] == "") {
	$_GET['p'] = "start";
}
if($_GET['lang'] == "") $_GET['lang'] = "en";

$file = $_GET['p'] . ".inc";
if(file_exists($file)) {
	include($file);
}else{
	include("error.inc");
}






	$mntmpl = "layout.tmpl";

$cnts = start();



if($_GET['lang'] == "de") {
	echo mkpage($cnts,$cnts["links"],$cnts["titel_de"],$mntmpl,$cnts["image"],"de");

}else{
	echo mkpage($cnts,$cnts["links"],$cnts["titel_en"],$mntmpl,$cnts["image"],"en");

}




function getfile($n) {
	$fp = @fopen($n,"r");
	$str = @fread($fp,filesize($n));
	@fclose($fp);
	return $str;
}

function mkpage($cnt,$links,$titel,$template,$img,$lang) {
	global $url,$imgurl,$cssfile,$current_path,$current_page;

	$layout = getfile($template);
	$layout = str_replace("#url",$url,$layout);


	$layout = str_replace("#t",$titel,$layout);
	$layout = str_replace("#year","2003-".date("Y"),$layout);
	$layout = str_replace("#lang",$lang,$layout);
	$query = getenv("QUERY_STRING");






	if($lang == "de") { $cnt = $cnt["cnt_de"]; }else{ $cnt = $cnt["cnt_en"]; }


	$cnt = str_replace('#url',$url,$cnt);
	$layout = str_replace("#c",$cnt,$layout);
	for($x=0;$x<sizeof($links);$x++) {

		if($links[$x]["text_en"] == "") { $links[$x]["text_en"] = $links[$x]["text_de"]; }
		$tlink =  $links[$x]["link"];
		if($links[$x]["target"] != "") {
			if($lang == "de") {
				$lnk.= '<p><a href="'.$tlink.'" target="'.$links[$x]["target"].'"><img src="images/list.gif" alt="" width="15" height="8" border="0">'.$links[$x]["text_de"].'</a></p>';
			}else{
				$lnk.= '<p><a href="'.$tlink.'" target="'.$links[$x]["target"].'"><img src="images/list.gif" alt="" width="15" height="8" border="0">'.$links[$x]["text_en"].'</a></p>';
			}
		}else{
			if($lang == "de") {
				$lnk.= '<p><a href="'.$tlink.'"><img src="images/list.gif" alt="" width="15" height="8" border="0">'.$links[$x]["text_de"].'</a></p>';
			}else{
				$lnk.= '<p><a href="'.$tlink.'"><img src="images/list.gif" alt="" width="15" height="8" border="0">'.$links[$x]["text_en"].'</a></p>';
			}
		}
	}
	$layout = str_replace("#l",$lnk	,$layout);








	$imgs = '<img src="images/icons/'.$img.'" width="150"><br><br><img src="images/people/01.jpg" width="150"><br><br><img src="images/objects/01.jpg" width="150">';
	$layout = str_replace("#i",$imgs	,$layout);

	return $layout;
}






?>