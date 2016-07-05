<?php
/**
 * @file
 * HybridAuth Dataporten specific settings.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'configuration_form_callback' => 'hybridauth_provider_dataporten_configuration_form_callback',
  'configuration_callback' => 'hybridauth_provider_dataporten_configuration_callback',
);

function hybridauth_provider_dataporten_configuration_form_callback(&$form, $provider_id) {
  $app_settings = &$form['vtabs']['application'];

  $app_settings['#description'] = t('On the server you must set the <strong>Redirect URI</strong> of the client to:<br/>'
    . '<strong>%redirect_uri</strong></p> <br/>'
    . '<p>Enter the <strong>Client ID</strong> and <strong>Client Secret</strong>',
    array(
      '%redirect_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'query' => array('hauth.done' => 'Dataporten'), 'language' => _hybridauth_language_default())),
    )
  );

  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_key']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#description']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#description']);
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('Client ID');
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('Client Secret');


}

function hybridauth_provider_dataporten_configuration_callback(&$config, $provider_id) {
  $config['scope'] = variable_get('hybridauth_provider_' . $provider_id . '_scope', 'read');
}
