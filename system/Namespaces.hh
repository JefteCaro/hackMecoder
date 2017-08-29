<?hh

namespace Hackme {

  namespace Controller {

    include 'system/Controller.hh';
    include 'system/Model.hh';
    function test() {
      echo 'Test from Controller';
    }

    function load(string $controller) {
      if(\Hackme\existController($controller)) {
        require 'application/controllers/'.\Hackme\strProper($controller).'.hh';

      } else {
        \Hackme\show404();
        exit;
      }
    }

    function get_index(string $controller) {
      if(method_exists(\Hackme\strProper($controller), 'index')) {
        $toCall = \Hackme\strProper($controller);
        $tmp = new $toCall();
        $tmp->index();
      } else {
        \Hackme\show404();
      }
    }

  }

  function InitDefault() {
    //echo route::$default_controller;
    if(\Hackme\existController(\Hackme\route::$default_controller)) {
      \Hackme\Controller\load(\Hackme\route::$default_controller);
      $proper = \Hackme\route::$default_controller;
      $def = new $proper();
      if(method_exists($def, 'index')) {
        $def->index();
      } else {
        \Hackme\show404();
      }
    } else {
      \Hackme\show404();
    }
  }

  function existController(string $controller):bool {

    if(file_exists(ROOTDIR.'/application/controllers/'.strProper($controller).'.hh')) {
      // echo ROOTDIR.'/application/controllers/'.strProper($controller).'.hh<br>';
      //  echo 'File Exists';
      return true;
    } else {
      // echo 'File Does not exists';
      return false;
    }
  }

  function show404() {
    echo 'Error: 404<br>File Not Found';
    exit;
  }

  function strProper(string $string):string {
    $f = str_split($string, 1);
    // echo $f[0].'<br>';
    $proper = str_replace(strtolower($f[0]), strtoupper($f[0]), $string );
    return $proper;
  }


}
