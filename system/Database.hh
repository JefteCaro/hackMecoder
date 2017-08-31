<?hh


/**
* CRUD
*
* Create - $this->insert(@param);
* Read - $this->query(@param);
* Update - $this->update(@param);
* Delete - $this->delete(@param);
*
*/


include SYSDIR.'ErrorLoader.hh';
class SQLHelper {
  public ?Awaitable $db;

  public $load;

  private $query;


  public function __construct() {
    // $this->do_connect();
    HH\Asio\join($this->set_connection());
    $this->load = new Loader();
  }
  //Returns
  public function get_host():string {
    return HH\Asio\join($this->async_host());
  }

  public function get_port():int {
    return HH\Asio\join($this->async_port());
  }

  public function get_server_info() {
    return HH\Asio\join($this->async_server_info());
  }

  //Private Functions
  private async function do_connect():
  Awaitable<\AsyncMysqlConnection> {
    $pool = new AsyncMysqlConnectionPool(array());
      $connect = await $pool->connect(
        \Hackme\db::$host,
        \Hackme\db::$port,
        \Hackme\db::$dbname,
        \Hackme\db::$dbuser,
        \Hackme\db::$dbpass
      );
      return $connect;
  }

  private async function set_connection():Awaitable<void> {
    $this->db = $this->do_connect();
  }

  private async function async_host():Awaitable<string> {
    $conn = await $this->do_connect();
    $return = $conn->host();
    $conn->close();
    return $return;
  }

  private async function async_port():Awaitable<int> {
    $conn = await $this->do_connect();
    $return = $conn->port();
    $conn->close();
    return $return;
  }

  private async function async_server_info():Awaitable<string> {
    $conn = await $this->do_connect();
    $return = $conn->serverInfo();
    $conn->close();
    return $return;
  }

/**
*
* @param $query_table
* @param $selection
* @param $where_args
* @param $order_by
* @param $order
*
*/
  public function query(string $query_table, ?string $selection = null, ?string $where_args = null, ?string $order_by = null, ?string $order = null):mixed {
    if($where_args!==null) {
      $async_where = ' WHERE '.$where_args;
    } else {
      $async_where = null;
    }

    if($selection==null) {
      $selection = '*';
    }

    if($order_by!== null) {
      $order_by = ' ORDER BY ' . $order_by. ' ' . $order;
    } else {
      $order_by = ' ';
      $order = '';
    }

      $this->query = 'SELECT '.$selection.' FROM '.$query_table. $async_where . $order_by;
      return $this;
  }

  private async function async_vector() {
    $conn =  await $this->do_connect();
    try {
      $result = await $conn->query($this->query);
      $conn->close();
      return $result->vectorRows();
    } catch (AsyncMysqlQueryException $e) {
      $err = new Errorloader();
      $err->error_exeption($e);
    }

  }
  public function row_array() {
    return HH\Asio\join($this->async_vector());
  }

  private async function async_map() {
    $conn =  await $this->do_connect();
    try {
      $result = await $conn->query($this->query);
      $conn->close();
      return $result->mapRows();
    } catch (AsyncMysqlQueryException $e) {
      $err = new Errorloader();
      $err->error_exeption($e);
    }

  }

  public function result_array() {
    return HH\Asio\join($this->async_map());
  }

  private async function async_insert($into_table, Contentvalues $data){
    $conn =  await $this->do_connect();

    try {
      $result = await $conn->query("INSERT INTO ".$into_table." (". $data->get_keys()->toSqlInsertKeys().") VALUES ".$data->get_values()->toSqlInsertValues().";");
      $conn->close();
    } catch (AsyncMysqlQueryException $e) {
      $err = new Errorloader();
      $err->error_exeption($e);
    }
  }

  private async function async_update($into_table, Contentvalues $data, $where_args) {
    $conn = await $this->do_connect();
    try {
      $result = await $conn->query("UPDATE ".$into_table." SET ".$data->toSqlUpdateString()." WHERE ".$where_args.";");
      $conn->close();
    } catch (AsyncMysqlQueryException $e) {
      $err = new Errorloader();
      $err->error_exeption($e);
    }
  }

  private async function async_delete($from_table, $where_args) {
    $conn = await $this->do_connect();
    try {
      $result = await $conn->query("DELETE FROM ".$from_table." WHERE ".$where_args.";");
      $conn->close();
    } catch (AsyncMysqlQueryException $e) {
      $err = new Errorloader();
      $err->error_exeption($e);
    }
  }
  public function insert($into_table, Contentvalues $data) {
    return HH\Asio\join($this->async_insert($into_table, $data));
  }

  public function update($into_table, Contentvalues $data, $where_args) {
    return HH\Asio\join($this->async_update($into_table, $data, $where_args));
  }

  public function delete($from_table, $where_args) {
    return HH\Asio\join($this->async_delete($from_table, $where_args));
  }


}
