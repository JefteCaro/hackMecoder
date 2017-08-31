<?hh

echo $getMessage;

if(!empty($getTrace)) {
  echo "<br><br>Backtrace: <br><br>";

  foreach ($getTrace as $key) {
    echo 'File: '.$key['file'].'<br>';
    echo 'Line: '.$key['line'].'<br><br>';
  }
}
