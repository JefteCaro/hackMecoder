<?hh


namespace Hackme {

  namespace Controller {

    function test() {
      echo 'Test from Controller';
    }

    function load(string $controller) {
      if(\Hackme\existDefault()) {
        require 'application/controllers/'.\Hackme\strProper(\Hackme\route::$default_controller).'.hh';

        // if($getIndex) {
        //   $tmp = new $controller();
        //   if(method_exists($controller, 'index')) {
        //     $tmp->index();
        //   } else {
        //     echo 'no index method';
        //   }
        // }

      } else {
        \Hackme\show404();
      }
    }

    function get_index(string $controller) {
      if(method_exists(\Hackme\strProper($controller), 'index')) {
        $toCall = \Hackme\strProper($controller);
        $tmp = new $toCall();
        $tmp->index();
      } else {
        echo "Error: No index found";
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

    \Hackme\Controller\load(\Hackme\route::$default_controller);

  }

  function existDefault():bool {

    if(file_exists(ROOTDIR.'/application/controllers/'.strProper(route::$default_controller).'.hh')) {
      // echo 'File Exists';
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
    $proper = str_replace(strtolower($f[0]), strtoupper($f[0]), route::$default_controller);
    return $proper;
  }


}
