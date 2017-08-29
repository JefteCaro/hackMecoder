<?hh
echo 'testview';

$data = Map {
  'tmp' => 'temporary1'
};

extract((array) $data);

echo $tmp;


foreach ($users as $item) {
  echo 'Id: '. $item['id'].'<br>';
  echo 'username: '. $item['username'].'<br>';
  echo 'password: '. $item['password'].'<br>';
  # code...
}
