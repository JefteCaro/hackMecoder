<?hh

class Contentvalues {

  public Map $data;

  public $tmpReturn;
  public function __construct() {
    // parent::__construct();
    $this->data = Map{};

  }
  public function put($stringKey, $stringValue) {
    $map = Vector{};
    if($this->key_exist($stringKey)) {
      $map = $this->data->at($stringKey)->add($stringValue);
    } else {
      $map->add($stringValue);
    }
    $tmp = Pair { $stringKey, $map};
    $this->data->add($tmp);
  }

  public function get_content(){
    $this->tmpReturn = $this->data;
    return $this;
  }
  public function get_keys() {
    $this->tmpReturn = $this->data->keys();
    return $this;
  }
  public function get_values() {
    $this->tmpReturn = $this->data->values();
    return $this;
  }
  public function key_exist($string) {
    if($this->data->containsKey($string)) {
      return true;
    } else {
      return false;
    }
  }
  public function toString():string {
    $tmpStr = '';
    for ($i=0; $i < count($this->tmpReturn); $i++) {
      if($i == count($this->tmpReturn) -1) {
        $tmpStr = $tmpStr .$this->tmpReturn[$i];
      } else {
        $tmpStr = $tmpStr .$this->tmpReturn[$i] . ", ";
      }
    }
    return $tmpStr;
  }
  public function toArray() {
    return $this->tmpReturn->toArray();
  }

  public function toSqlInsertKeys() {
    $tmp = $this->tmpReturn->toArray();
    echo implode(', ', $tmp);
    return implode(', ', $tmp);
    // var_dump($tmp);
  }

  public function toSqlInsertValues() {
    $return = '';
    $tmp = $this->tmpReturn;
    // echo count($tmp);
    for ($i=0; $i <= count($tmp); $i++) {
      $return = $return . "(\"";
      foreach ($tmp as $key) {
        //echo $key[$i]."<br>";
        // $tmp2 = $tmp2 . $key[$i] . "\", \"";
        $return = $return . $key[$i] . "\", \"";
      }
      $return = substr_replace($return, "", strlen($return) - 4, 3) . "), ";
      // echo '<br>';
    }
    // echo $return;
    return substr_replace($return, "", strlen($return) - 2, 1);
  }

  public function toSqlUpdateString() {
    $return = '';
    $keys = $this->get_keys()->toArray();


    for ($i=0; $i < count($keys); $i++) {
      $vals = $this->data->at($keys[$i]);
      $return = $return . $keys[$i] . "=\"" .$vals[0]. "\", ";
      // var_dump($vals);
      // var_dump($vals[$keys[$i]]);
    }

    // var_dump($vals->toArray());

    return substr_replace($return, "", strlen($return) - 2, 1);
    // foreach ($tmp as $key) {
    //   var_dump($key);
    //   echo '</br>';
    // }
  }


}
