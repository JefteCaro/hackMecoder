<?hh

class Test_model extends HM_Model {

  public function __construct() {
    parent::__construct();
  }

  public function get_users() {
    return $this->db->query('users', null, null, null, null);
  }

}
