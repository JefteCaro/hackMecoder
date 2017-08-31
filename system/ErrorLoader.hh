<?hh

class Errorloader {
  public $load;
  public function error_exeption(Exception $e) {
    $this->load = new Loader();
    $err = Map {
      'getMessage' => $e->getMessage(),
      'getTrace' => $e->getTrace()
    };
    extract((array)$err);
    $this->load->view('errors/error', $err);
  }
}
