<?hh

class HM_Model {

  public $db;
  public $load;
  public function __construct() {
    $this->load_database();
  }

  private function load_database() {
    include SYSDIR.'Database.hh';
    $this->db = new SQLHelper();
  }

}
