import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        String s = sc.nextLine ( );
        int n = s.length ( );
        int [ ] [ ] dp = new int [ n ] [ 13 ];
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < 13 ; j ++ ) {
                dp [ i ] [ j ] = 0;
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( i == 0 ) {
                if ( s.charAt ( i )!= '?' ) {
                    dp [ i ] [ ( int ) s.charAt ( i ) - '0' ] = 1;
                } else {
                    for ( int j = 0 ; j < 10 ; j ++ ) {
                        dp [ i ] [ j ] = 1;
                    }
                }
            } else {
                if ( s.charAt ( i )!= '?' ) {
                    for ( int j = 0 ; j < 13 ; j ++ ) {
                        for ( int k = 0 ; k < 10 ; k ++ ) {
                            dp [ i ] [ ( j * 10 + k ) % 13 ] += dp [ i - 1 ] [ j ];
                        }
                    }
                } else {
                    for ( int j = 0 ; j < 10 ; j ++ ) {
                        for ( int k = 0 ; k < 13 ; k ++ ) {
                            dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ];
                        }
                    }
                }
                for ( int j = 0 ; j < 13 ; j ++ ) {
                    dp [ i ] [ j ] %= 1000000007;
                }
            }
        }
        System.out.println ( dp [ n - 1 ] [ 5 ] );
    }
}
