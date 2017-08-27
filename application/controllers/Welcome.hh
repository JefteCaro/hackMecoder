<?hh
//
// class Welcome extends Controller {
//
//   public $tmp;
//   public function __construct() {
//     parent::__construct();
//     echo 'Testing from Welcome Controller';
//     $this->load->model('test_model');
//   }
//
//   public function test() {
//     $tmp = $this->load->view('testview');
//     echo 'Tst Funcion';
//     //var_dump($this->load->model('test_model'));
// //    $this->test_model->get();
//   echo '<br><br><br><br>';
//     // var_dump($this->test_model->get());
//   }
//
// }


class Welcome {

  public function __construct() {
    // parent::__construct();
    //echo 'Welcome Controller';
    // echo $_SERVER['HTTP_HOST'];
    // echo $_SERVER['REQUEST_URI'];
    // echo '<br>';
    // echo $this->uri;
  }
  public function index() {
    echo 'Index';
  }
  public function test() {
    echo 'Test Function';
  }

  public function testing($tmp = '') {
    if($tmp == '') {
      echo 'testing function without value';
    } else {
      echo 'testing function with value : '. $tmp;
    }
  }
}
new Welcome();
