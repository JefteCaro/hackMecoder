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


class Welcome extends HM_Controller {

  public $test_model;
  public function __construct() {
    parent::__construct();
    $this->test_model = $this->model('Test_model');
  }
  public function index() {
    $data = Map {
      'users' => $this->test_model->get_users()
    };

    $this->view('testview', $data);
        //   var_dump($key). '<br><br><br>';
    // }
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

  public function test_multi($tmp1 = '1', $tmp2 = '2') {
    echo 'Test Multi Value';
  }
}
new Welcome();
