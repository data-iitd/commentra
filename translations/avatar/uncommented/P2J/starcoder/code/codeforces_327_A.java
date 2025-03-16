import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        String s = sc.next ( ).replace ( "", "" );
        if ( s.indexOf ( '0' ) == -1 ) {
            System.out.println ( n - 1 );
        } else {
            int [ ] indices = new int [ s.length ( ) ];
            for ( int i = 0 ; i < s.length ( ) ; i++ ) {
                indices [ i ] = i;
            }
            Arrays.sort ( indices, ( a, b ) -> s.charAt ( a ) - s.charAt ( b ) );
            int maximum = 0;
            for ( int i = 0 ; i < indices.length - 1 ; i++ ) {
                for ( int j = i + 1 ; j < indices.length ; j++ ) {
                    maximum = Math.max ( maximum, 2 + 2 * ( Math.abs ( indices [ i ] - indices [ j ] ) - 1 ) - ( Math.abs ( i - j ) - 1 ) );
                }
            }
            System.out.println ( s.replaceAll ( "0", "" ).length ( ) + maximum );
        }
    }
}
