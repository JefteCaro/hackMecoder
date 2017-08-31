<?hh
set_error_handler('error_handler');


function error_handler($er1, $er2, $er3, $er4){

  echo $er1 . '<br>';
  echo $er2 . '<br>';
  echo $er3 . '<br>';
  echo $er4 . '<br>';
}

/**
 * hackmeCoder - Hacklang MVC Framework
 *
 * @package hackmeCoder
 * @author Jefte Caro
 * @copyright Copyright (c) 2017, Jefte Caro
 * @status Under Development
 * @Files
 * |
 * |---application
 * |------controllers
 * |---------Welcome.hh
 * |------model
 * |---------Test_model.hh
 * |------views
 * |---------testview.hh
 * |---system
 * |------Config.hh
 * |------Controller.hh
 * |------Database.hh
 * |------Loader.hh
 * |------Model.hh
 * |------Namespaces.hh
 * |------Router.hh
 * |---.hhconfig
 * '---index.hh
 *
 **/
$config['system_folder'] = 'system';
$config['application']   = 'application';

define('ROOTDIR', realpath(__DIR__));

extract((array)$config);

define('SYSDIR', $system_folder.'/');
define('APPDIR', $application.'/');


include SYSDIR.'Config.hh';
require_once SYSDIR.'Namespaces.hh';
require SYSDIR.'Router.hh';
