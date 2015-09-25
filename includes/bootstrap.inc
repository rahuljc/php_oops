<?php

spl_autoload_register('__my_auto_loader');

function __my_auto_loader($className){
  require_once("class/Game.php");
}

function page_not_found(){
	print "Page not found ! \n";
}


$url = parse_url($_SERVER['REQUEST_URI']);
$segments = array_slice(explode("/", $url['path']), 3);

$className = $segments[0];
$actionName = $segments[1];


if(file_exists("class/$className.php")){
	require_once("class/$className.php");
	$obj = new $className();
	if (isset($actionName)){
		$obj->{$actionName}();	
	}else{
		page_not_found();
	}
	
}else{
	page_not_found();
}


echo "End of Page";


?>