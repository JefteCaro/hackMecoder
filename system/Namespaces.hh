<?hh


namespace Hackme {

  namespace Controller {

    function test() {
      echo 'Test from Controller';
    }

    function load(string $controller) {
      if(\Hackme\existController($controller)) {
        require 'application/controllers/'.\Hackme\strProper($controller).'.hh';

      } else {
        show404();
        exit;
      }
    }

    function get_index(string $controller) {
      if(method_exists(\Hackme\strProper($controller), 'index')) {
        $toCall = \Hackme\strProper($controller);
        $tmp = new $toCall();
        $tmp->index();
      } else {
        show404();
      }
    }

  }

  namespace Loader {

    function test() {
      echo 'Test from Loader';
    }
  }


  function InitDefault() {
    //echo route::$default_controller;
    if(existController(route::$default_controller)) {
      \Hackme\Controller\load(\Hackme\route::$default_controller);

    } else {
      show404();
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
