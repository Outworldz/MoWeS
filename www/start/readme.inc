<?php


function start() {

settype($vars,"array");
if($_GET['action'] == "") {
$vars["cnt_de"] = '
<h3>MoWeS Portable II 2.2.3</h3>

<div style="background-color:red;padding: 10px 10px 10px 10px;"><strong>Wichtiger Hinweis</strong><br>
Wenn Sie eine Applikationspaket (TYPO3, Joomla, WordPress etc.) installiert haben, dass einen Login benötigt, so ist der Administratorenlogin immer "admin" mit dem Passwort "password"!
</div><br>

Willkommen bei MoWeS Portable II! Bitte lesen Sie diese Seite genau durch, Sie enthält wichtige Informationen!<br>
MoWeS Portable - Das ist Ihr Webserver für überall. Kopieren Sie ihn einfach in ein beliebiges Verzeichnis. (z.B. auf einen USB Stick, eine Speicherkarte, Ihre Festplatte).<br><br>
<b>Bitte benutzen Sie regelmäßig die "Update"-Funktion in MoWeS</b>

<p>
<ul>
	<li><a href="http://mowesforum.chsoftware.net">MoWeS Forum</a> (Fragen und Probleme können hier gepostet werden)</li>
	<li><a href="http://moweswiki.chsoftware.net">MoWeS Wiki</a> (Umfangreiche Dokumentation und Hilfe)</li>
	<li><a href="http://moweshelp.chsoftware.net">MoWeS Help</a> (Tutorial und häufige Fragen)</li>
</ul>

</p>



';




$vars["cnt_en"] = '
<h3>MoWeS Portable II 2.2.3</h3>

<div style="background-color:red;padding: 10px 10px 10px 10px;"><strong>Important notice</strong><br>
If you have installed an application package (TYPO3, Joomla, WordPress etc.), the administration login always will be "admin" with the password "password"!
</div><br>

Welcome to MoWeS Portable II! Please read this page carefully. It contains important informations!
MoWeS Portable - This is your webserver for anywhere. Just copy the src folder somewhere you want. (eg. on a usb stick, a flash card, your harddisk).<br>

<b>Please use regularly the "Update"-function in MoWeS</b>
<p>
<ul>
	<li><a href="http://mowesforum.chsoftware.net">MoWeS Forum</a> (You can post questions and problems)</li>
	<li><a href="http://moweswiki.chsoftware.net">MoWeS Wiki</a> (Comprehensive documentation and help ressource)</li>
	<li><a href="http://moweshelp.chsoftware.net">MoWeS Help</a> (Tutorial and FAQs)</li>
</ul>

</p>


';


if($_GET['first'] == "true") {
	$vars["cnt_de"] = '<div style="background-color:red;padding-left:10px;padding-top:10px;padding-right:10px; padding-bottom:10px; font-weight:bold;">Klicken Sie links auf Zurück um zur Hauptseite zu gelangen.</div>' . $vars["cnt_de"];
	$vars["cnt_en"] = '<div style="background-color:red;padding-left:10px;padding-top:10px;padding-right:10px; padding-bottom:10px; font-weight:bold;">Click on Back on the left to get to the main page.</div>' . $vars["cnt_en"];
	$vars["links"][0]["text_de"] = '<span style="color:red"><blink>Zurück</blink></span>';
	$vars["links"][0]["text_en"] = '<span style="color:red"><blink>Back</blink></span>';
}else{
	$vars["links"][0]["text_de"] = 'Zurück';
	$vars["links"][0]["text_en"] = "Back";

}

$vars["image"] = "mowes.jpg";
}

$vars["titel_de"] = "Informationen";
$vars["titel_en"] = "Informations";

$vars["links"][0]["link"] = "index.php?lang=".$_GET['lang'];


return $vars;
}


?>