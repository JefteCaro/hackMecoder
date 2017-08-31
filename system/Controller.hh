<?hh


  class HM_Controller {

    public $load;
    public function __construct() {
      $this->init();
      require_once SYSDIR.'Namespaces.hh';
    }

    public function model(string $modelname){
      // include 'application/model/'.$modelname.'.hh';
      // return new $modelname();
      $proper = Hackme\strProper($modelname);
      include 'application/model/'.$proper.'.hh';
      $newClass = new $proper();
      return $newClass;
    }

    public function view(string $viewname, ?Map $data) {
      extract((array) $data);
      include 'application/views/'.$viewname.'.hh';
    }

    private function init() {
      $this->load = new Loader();
    }

  }
