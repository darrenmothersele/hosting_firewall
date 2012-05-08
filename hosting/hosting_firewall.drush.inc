<?php

function hosting_firewall_hosting_site_context_options(&$task) {
  if (isset($task->ref->hosting_firewall) && !empty($task->ref->hosting_firewall)) {
    $task->context_options['hosting_firewall'] = $task->ref->hosting_firewall;
  } else {
    $task->context_options['hosting_firewall'] = 'null';
  }
}

function hosting_firewall_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->hosting_firewall) && !empty($context->hosting_firewall)) {
      $node->hosting_firewall = $context->hosting_firewall;
    }
  }
}
