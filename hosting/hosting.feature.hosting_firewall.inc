<?php

function hosting_firewall_hosting_feature() {
  $features['hosting_firewall'] = array(
    'title' => t('Simple Hosting Firewall'),
    'description' => t('Allows admins to restrict HTTP access by IP address'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_firewall',
    'group' => 'experimental',
  );
  return $features;
}
