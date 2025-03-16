
import java.io.IOException ; // Import the IOException class for handling input/output exceptions
import java.time.LocalTime ; // Import the LocalTime class for handling time
import java.util.Scanner ; // Import the Scanner class for reading input from the console

public class Main {

  public static void main ( String [ ] args ) throws IOException {
    // Create a new Scanner object to read input from the console
    Scanner sc = new Scanner ( System.in ) ;

    // Read the first time string from the console and split it into hour and minute parts
    String [ ] s = sc.next ( ).split ( ":" ) ;

    // Read the second time string from the console and split it into hour and minute parts
    String [ ] t = sc.next ( ).split ( ":" ) ;

    // Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
    LocalTime x = LocalTime.of ( Integer.parseInt ( s [ 0 ] ) , Integer.parseInt ( s [ 1 ] ) ) ;
    LocalTime y = LocalTime.of ( Integer.parseInt ( t [ 0 ] ) , Integer.parseInt ( t [ 1 ] ) ) ;

    // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
    System.out.println ( x.minusHours ( y.getHour ( ) ).minusMinutes ( y.getMinute ( ) ) ) ;
  }
}