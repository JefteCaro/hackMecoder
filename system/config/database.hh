<?hh

include 'system/config/config.hh';
class ConnectionInfo {
  public ?Awaitable $db;

  public function __construct() {
    // $this->do_connect();
    HH\Asio\join($this->set_connection());

  }
  //Returns
  public function get_host():string {
    return HH\Asio\join($this->db_host());
  }

  public function get_port():int {
    return HH\Asio\join($this->db_port());
  }

  public function get_server_info() {
    return HH\Asio\join($this->db_server_info());
  }

  //Private Functions
  private async function do_connect():
  Awaitable<\AsyncMysqlConnection> {
    $pool = new AsyncMysqlConnectionPool(array());
    return await $pool->connect(
      \Hackme\db::$host,
      \Hackme\db::$port,
      \Hackme\db::$dbname,
      \Hackme\db::$dbuser,
      \Hackme\db::$dbpass
    );
  }

  private async function set_connection():Awaitable<void> {
    $this->db = $this->do_connect();
  }

  private async function db_host():Awaitable<string> {
    $conn = await $this->do_connect();
    $return = $conn->host();
    $conn->close();
    return $return;
  }

  private async function db_port():Awaitable<int> {
    $conn = await $this->do_connect();
    $return = $conn->port();
    $conn->close();
    return $return;
  }

  private async function db_server_info():Awaitable<string> {
    $conn = await $this->do_connect();
    $return = $conn->serverInfo();
    $conn->close();
    return $return;
  }



  private async function db_query(string $query_table,?string $selection, ?string $where_args, ?string $order_by, ?string $order):Awaitable {
    // $conn = $this->db;
    $conn =  await $this->do_connect();

    if($where_args!==null) {
      $db_where = ' WHERE '.$where_args;
    } else {
      $db_where = null;
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

    $result = await $conn->query('SELECT '.$selection.' FROM '.$query_table. $db_where . $order_by);
    $conn->close();
    return $result->mapRows();
  }

  public function query(string $query_table, ?string $selection, ?string $where_args, ?string $order_by, ?string $order):mixed {
    return HH\Asio\join($this->db_query($query_table, $selection, $where_args, $order_by, $order));
  }


}
