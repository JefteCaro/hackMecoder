<?hh


  class HM_Controller {


    public function __construct() {

    }

    public function model(string $modelname){
      // include 'application/model/'.$modelname.'.hh';
      // return new $modelname();
      include 'application/model/'.$modelname.'.hh';
      $newClass = new $modelname();
      return $newClass;
    }

    public function view(string $viewname, ?Map $data) {
      extract((array) $data);
      include 'application/views/'.$viewname.'.hh';
    }

  }
