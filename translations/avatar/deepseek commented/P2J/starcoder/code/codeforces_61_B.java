import java.util.*;
import java.io.*;

public class Main {

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int t = sc.nextInt ( );
        while ( t-- > 0 ) {
            String [ ] l = new String [ 3 ];
            for ( int i = 0 ; i < 3 ; i++ ) l [ i ] = sc.next ( );
            String [ ] p = new String [ 3 ];
            for ( int i = 0 ; i < 3 ; i++ ) p [ i ] = sc.next ( );
            int n = sc.nextInt ( );
            for ( int i = 0 ; i < n ; i++ ) {
                String s = sc.next ( );
                boolean f = false;
                for ( int j = 0 ; j < 3 ; j++ ) {
                    if ( s.equals ( l [ j ] ) ) {
                        f = true;
                        break;
                    }
                }
                if ( f ) System.out.println ( "ACC" );
                else System.out.println ( "WA" );
            }
        }
    }
}

