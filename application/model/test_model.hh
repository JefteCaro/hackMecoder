<?hh

class test_model extends Model {
  public function __construct() {
    parent::__construct();
    echo 'testing from Model';
  }

  public function get() {
    return 'function get';
  }
}

new testmodel();
