<?hh

namespace Hackme {

    class db {

      public static string $host = 'localhost';
      public static int $port = 3306;
      public static string $dbname = 'test';
      public static string $dbuser = 'root';
      public static string $dbpass = 'root';
    }

    final class route {
      public static string $default_controller = 'Welcome';

    }
}
