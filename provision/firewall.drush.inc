<?php


function firewall_provision_services() {
	return array('firewall' => NULL);
}

class provisionService_firewall extends provisionService {
	public $service = 'firewall';
	static function subscribe_site($context) {
		$context->setProperty('hosting_firewall');
	}
}

function firewall_provision_apache_vhost_config($uri, $data) {
	$lines = array();
	$rules = d()->hosting_firewall;
	$ips = explode("\n", $rules);
	if (!empty($rules) && $rules != 'null') {
		$root = d()->root;
		$lines[] = " <Directory \"$root\">";
		$lines[] = "   # Simple Firewall rules added by Aegir";
		$lines[] = "   order deny,allow";
		$lines[] = "   deny from all";
		foreach ($ips as $ip) {
			$ip = trim($ip);
			$lines[] = "   allow from {$ip}";
		}
		$lines[] = " </Directory>";
	}
	drush_print('firewall debug');
	return implode("\n", $lines);
}