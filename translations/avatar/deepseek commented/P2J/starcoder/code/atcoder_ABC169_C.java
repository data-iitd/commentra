
import java.util.*;
import java.io.*;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        
        String [ ] inputs = sc.nextLine ( ).split ( " " );
        int a = Integer.parseInt ( inputs [ 0 ] );
        int b = ( int ) ( Double.parseDouble ( inputs [ 1 ] ) * 100 + 0.1 );
        
        System.out.println ( a * b / 100 );
    }
}

