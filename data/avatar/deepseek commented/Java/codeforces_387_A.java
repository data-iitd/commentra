
import java.io.IOException ; 
import java.time.LocalTime ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
        Scanner sc = new Scanner ( System.in ) ; 
        String [ ] s = sc.next ( ).split ( ":" ) ; 
        String [ ] t = sc.next ( ).split ( ":" ) ; 
        LocalTime x = LocalTime.of ( Integer.parseInt ( s [ 0 ] ) , Integer.parseInt ( s [ 1 ] ) ) ; 
        LocalTime y = LocalTime.of ( Integer.parseInt ( t [ 0 ] ) , Integer.parseInt ( t [ 1 ] ) ) ; 

        // Step 2: Calculate the difference between the two times
        System.out.println ( x.minusHours ( y.getHour ( ) ).minusMinutes ( y.getMinute ( ) ) ) ; 
    } 
}

