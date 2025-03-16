

import java. util. Arrays ;
import java. util. Scanner ;

public class atcoder_ABC123_D{
    public static void main ( String [ ] args ) {
        Scanner scanner = new Scanner ( System. in ) ;
        int x = scanner. nextInt ( ) ;
        int y = scanner. nextInt ( ) ;
        int z = scanner. nextInt ( ) ;
        int k = scanner. nextInt ( ) ;
        int [ ] a = new int [ x ] ;
        int [ ] b = new int [ y ] ;
        int [ ] c = new int [ z ] ;
        for ( int i = 0 ; i < x ; i ++ ) {
            a [ i ] = scanner. nextInt ( ) ;
        }
        for ( int i = 0 ; i < y ; i ++ ) {
            b [ i ] = scanner. nextInt ( ) ;
        }
        for ( int i = 0 ; i < z ; i ++ ) {
            c [ i ] = scanner. nextInt ( ) ;
        }
        int [ ] ab = new int [ x * y ] ;
        int index = 0 ;
        for ( int i = 0 ; i < x ; i ++ ) {
            for ( int j = 0 ; j < y ; j ++ ) {
                ab [ index ++ ] = a [ i ] + b [ j ] ;
            }
        }
        Arrays. sort ( ab ) ;
        int [ ] abc = new int [ Math. min ( x * y, k ) ] ;
        index = 0 ;
        for ( int i = 0 ; i < Math. min ( x * y, k ) ; i ++ ) {
            for ( int j = 0 ; j < z ; j ++ ) {
                abc [ index ++ ] = ab [ i ] + c [ j ] ;
            }
        }
        Arrays. sort ( abc ) ;
        for ( int i = 0 ; i < k ; i ++ ) {
            System. out. println ( abc [ abc. length - 1 - i ] ) ;
        }
        // Printing the first k elements of abc in descending order
    }
}

