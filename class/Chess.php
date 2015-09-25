<?php

class Chess extends Game {

	public function __construct(){
		$this->game_name= "Chess";
	}

	public function displayName(){
		print "You are currently viewing: ". $this->game_name ."";
	}
}


?>