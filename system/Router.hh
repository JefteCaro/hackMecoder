<?hh

class HM_Router {
  public function __construct() {

    // echo 'test<br>';//Hackme\InitDefault();
    // echo $_SERVER['REQUEST_URI'];

    $tmpURL = explode('/', $_SERVER['REQUEST_URI']);
    // var_dump($tmpURL );

    // echo '<br>tmpURL[0] : '.$tmpURL[0].'<br>';
    //start routing
    if(empty($tmpURL[1])) {
      Hackme\InitDefault();
    } else {
      Hackme\Controller\load($tmpURL[1]);
    }

    $proper = \Hackme\strProper($tmpURL[1]);
    $tmp = new $proper();
    if(empty($tmpURL[2])) {
      if(method_exists($proper, 'index')) {
        $tmp->index();
      } else {
        echo 'No index method found.';
      }
    } else {
      if(method_exists($proper, $tmpURL[2])) {
        if(empty($tmpURL[3])) {
          $tmp->$tmpURL[2]();
        } else {
            $tmp->$tmpURL[2]($tmpURL[3]);
        }

      } else {
        Hackme\show404();
      }
    }

  }
}

new HM_Router();
