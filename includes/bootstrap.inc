<?php

spl_autoload_register('__my_auto_loader');

function __my_auto_loader($className){
  require_once("class/Game.php");
}

function page_not_found(){
	header("HTTP/1.0 404 Not Found");
	include_once("page_not_found.html");
	exit;
}

$url = parse_url($_SERVER['REQUEST_URI']);
$segments = explode("/", $url['path']);


if(empty($segments) || ($url['path']=="/")){
	$className = 'Home';
	$actionName = "index";
}else{
	$className  = isset($segments[1]) ? $segments[1]:'Home';
	$actionName = isset($segments[2]) ? $segments[2]: 'index';	
}


if(file_exists("class/$className.php")){
	require_once("class/$className.php");
	$obj = new $className();
	if (method_exists($obj, $actionName)){
		$obj->{$actionName}();
	}else{
		page_not_found();
	}
}else{
	page_not_found();
}

?>