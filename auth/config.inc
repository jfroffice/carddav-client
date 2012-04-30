<?php
	// auth method: generic (auth/plugins/generic_conf.inc) or ldap (auth/plugins/ldap_conf.inc)
	$config['auth_method']='generic';

	// set to true for debugging XML response, otherwise set to false to avoid browser
	//  to show http authentication window after unsuccessful authentication
	$config['auth_send_authenticate_header']=false;

	// successfull authentication XML specification (change the "http://www.server.com:80" to your protocol/server/port)
	$config['accounts']=array('resource'=>array());

	$config['accounts']['resource'][]=array(
		'carddav'=>array(
			'href'=>'http://www.server.com:80/caldav.php/'.$_SERVER['PHP_AUTH_USER'].'/',
			'crossdomain'=>'false',	// set to true for different protocol/server/port origin
			'withcredentials'=>'false',	// if true, Access-Control-Allow-Origin "*" is not allowed
			'userauth'=>array(
				'username'=>$_SERVER['PHP_AUTH_USER'],
				'password'=>$_SERVER['PHP_AUTH_PW']
			),
			'syncinterval'=>30000,
			'timeout'=>30000,
			'locktimeout'=>10000
		)
	);

/*
	// additional carddav accounts
	$config['accounts']['resource'][]=array(
		'carddav'=>array(
			'href'=>'http://www.server.com:80/caldav.php/shared_resource/',
			'crossdomain'=>'false',	// set to true for different protocol/server/port origin
			'withcredentials'=>'false',	// if true, Access-Control-Allow-Origin "*" is not allowed
			'userauth'=>array(
				'username'=>$_SERVER['PHP_AUTH_USER'],
				'password'=>$_SERVER['PHP_AUTH_PW']
			),
			'syncinterval'=>30000,
			'timeout'=>30000,
			'locktimeout'=>10000
		)
	);
*/

?>