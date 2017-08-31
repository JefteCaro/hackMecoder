<?hh

class Welcome extends HM_Controller {

  public $test_model;
  public function __construct() {
    parent::__construct();
    $this->test_model = $this->model('test_model');

  }
  public function index() {
    $data = Map {
      'users' => $this->test_model->get_users()
    };
    $this->load->model('Test_model');
    $this->load->view('testview', $data);
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
