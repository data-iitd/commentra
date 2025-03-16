
import java.io.IOException ; # Import the IOException class for handling input/output exceptions
import java.time.LocalTime ; # Import the LocalTime class for handling time
import java.util.Scanner ; # Import the Scanner class for reading input from the console

public class Main:

  public static void main ( String [ ] args ) throws IOException:
    # Create a new Scanner object to read input from the console
    sc = Scanner ( System.in )

    # Read the first time string from the console and split it into hour and minute parts
    s = sc.next ( ).split ( ":" )

    # Read the second time string from the console and split it into hour and minute parts
    t = sc.next ( ).split ( ":" )

    # Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
    x = LocalTime.of ( int ( s [ 0 ] ) , int ( s [ 1 ] ) )
    y = LocalTime.of ( int ( t [ 0 ] ) , int ( t [ 1 ] ) )

    # Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
    print ( x.minusHours ( y.getHour ( ) ).minusMinutes ( y.getMinute ( ) ) )

