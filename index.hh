<?hh
set_error_handler('error_handler');

function error_handler($er1, $er2, $er3, $er4){

  echo $er1 . '<br>';
  echo $er2 . '<br>';
  echo $er3 . '<br>';
  echo $er4 . '<br>';
}

define('ROOTDIR', realpath(__DIR__));



include 'system/config/config.hh';
require 'system/Namespaces.hh';
require 'system/Router.hh';


// $base_url = $_SERVER['HTTP_HOST'];
// header('Location://'.$_SERVER['HTTP_HOST'].'/');
// class HHVMC {
//
//   public function __construct() {
//
//     // echo 'HHVMC';
//
//
//
//     // echo $_SERVER['SCRIPT_URI'].$_SERVER['REQUEST_URI'];
//
//     //header("Location://".strtolower($_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']));
//
//     //END ROUTING
//
//     // if($tmpURL)
//     // $tmp  = array();
//     // $tmp = $_SERVER;
//     // var_dump($tmp);
//     // foreach ($_SERVER as $key) {
//     //   echo $_SERVER[$key].'<br>';
//     // }
//
//   }
// }
//
//
// new HHVMC();
