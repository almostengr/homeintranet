<?php
/**
 * @file
 * home_intranet.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function home_intranet_default_mailhandler_mailbox() {
  $export = array();

  $mailbox = new stdClass();
  $mailbox->disabled = FALSE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'tharam04_gmail_com';
  $mailbox->admin_title = 'tharam04@gmail.com';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'MyHub',
    'domain' => 'imap.gmail.com',
    'port' => '993',
    'insecure' => 0,
    'name' => 'tharam04@gmail.com',
    'pass' => 'dsyboywpckfeibqq',
    'extraimap' => '/ssl',
    'limit' => '',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 0,
    'fromheader' => 'From',
    'security' => '0',
    'replies' => '1',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
    'readonly' => 0,
  );
  $export['tharam04_gmail_com'] = $mailbox;

  return $export;
}
