

import java.time.LocalTime ; 
import java.util.* ; 

def main ( ) : 
    # Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    sc = Scanner ( System.in ) ; 
    s = sc.next ( ).split ( ":" ) ; 
    t = sc.next ( ).split ( ":" ) ; 
    x = LocalTime.of ( Integer.parseInt ( s [ 0 ] ), Integer.parseInt ( s [ 1 ] ) ) ; 
    y = LocalTime.of ( Integer.parseInt ( t [ 0 ] ), Integer.parseInt ( t [ 1 ] ) ) ; 

    # Step 2: Calculate the difference between the two times
    print ( x.minusHours ( y.getHour ( ) ).minusMinutes ( y.getMinute ( ) ) ) ; 

