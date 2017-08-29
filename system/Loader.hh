<?hh

class Loader {

  public function __construct() {

  }
  
  public function view(string $viewname, ?Map $data) {
    extract((array) $data);
    include 'application/views/'.$viewname.'.hh';
  }

  public function model(string $modelname) {
    $data = Map {
      $modelname => new $modelname()
    };

    extract((array) $data);
    // var_dump($data);
    // return $this ==> $this->$modelname;
    include 'application/model/'.$modelname.'.hh';
  }
  private function load_class(string $classname) {
    $tmp = new $classname();
    return $tmp;
  }

}
