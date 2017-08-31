<?hh

class Test_model extends HM_Model {

  public function __construct() {
    parent::__construct();
  }

  public function get_users() {
    $result = $this->db->query('users');
    // $this->db->insert();

  // var_dump($a->key_exist('passwordd'));
  echo '<br>';
  echo '<br>';
  // $a->get_keys()->toSqlInsertKeys();
  $a = new Contentvalues();
  $a->put('username', 'new username');
  $a->put('password', 'new Password');
  // echo $a->toSqlUpdateString();
  // $this->db->update('users', $a, 'id=3');
  echo '<br><br>';
  echo '<br>';
  echo '<br>';
  return $result->result_array();
  }

  public function get_query() {

  }
}
