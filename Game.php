<?php

class Game {

	public $game_name = '';

	public function __construct($name){
	   $this->game_name= $name;
	   print "Game ". $this->game_name." initialized";
	}

}

?>