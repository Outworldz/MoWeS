<?php


  $url = "http://localhost/";






function getrand($max) {
srand ((double)microtime()*1000000);
$randval = rand();
$aa = rand(1,$max);
return $aa;
}










?>
