<?hh


/**
* Routing Method
*
**/
class HM_Router {

  public function __construct() {


    /**
    * Routing Method
    *
    * exploded the $_SERVER['REQUEST_URI'] by "/"
    * and stored it in $tmpURL array
    *
    * eg.
    *
    * --- Routing pattern ---
    * http://localhost:80/controller/function-from-controller/function_parameters
    *
    * once exploded the $tmpURL will have the values as follows
    *
    * $tmpURL[0]  -  localhost:80
    * $tmpURL[1]  -  controller
    * $tmpURL[2]  -  function-from-controller
    * $tmpURL[3]  -  function_parameters
    *
    *
    */
    $tmpURL = explode('/', $_SERVER['REQUEST_URI']);

    /**
    * just needed to load this first
    */
    require_once SYSDIR.'Loader.hh';


    if(empty($tmpURL[1])) {
      /**
      * when we requested the baseurl of, this gives us an empty controller,
      * thus, we must load a default controller that has and 'index' function
      * so that we can have our default output
      */
      Hackme\InitDefault();

    } else {
      /**
      * now that we have specified our controller in the URL, we can now
      * load the requested controller class
      */
      Hackme\Controller\load($tmpURL[1]);
    }

    if(!empty($tmpURL[1])) {

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
}

/**
* This is the most important part in this file.
* since we have declared our router as a class, we must intitialize
* the class in order to run the routing request.
**/
new HM_Router();
