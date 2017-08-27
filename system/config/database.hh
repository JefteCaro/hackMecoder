<?hh


class ConnectionInfo {
  public function __construct() {
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
  private async function do_connect(\AsyncMysqlConnectionPool $pool):
  Awaitable<\AsyncMysqlConnection> {
    return await $pool->connect(
      db::$host,
      db::$port,
      db::$dbname,
      db::$dbuser,
      db::$dbpass
    );
  }

  private async function db_host():Awaitable<string> {
    $pool = new AsyncMysqlConnectionPool(array());
    $conn = await $this->do_connect($pool);
    $return = $conn->host();
    $conn->close();
    return $return;
  }

  private async function db_port():Awaitable<int> {
    $pool = new AsyncMysqlConnectionPool(array());
    $conn = await $this->do_connect($pool);
    $return = $conn->port();
    $conn->close();
    return $return;
  }

  private async function db_server_info():Awaitable<string> {
    $pool = new AsyncMysqlConnectionPool(array());
    $conn = await $this->do_connect($pool);
    $return = $conn->serverInfo();
    $conn->close();
    return $return;
  }


}
