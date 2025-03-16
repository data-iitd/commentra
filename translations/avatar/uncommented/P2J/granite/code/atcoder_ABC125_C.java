
import java.util.*;
import java.io.*;

class atcoder_ABC125_C {
    static int gcd ( int a, int b ) {
        if ( b == 0 ) return a;
        return gcd ( b, a % b );
    }
    static int[] ruiseki_lr ( int[] array ) {
        int e = 0;
        int n = array.length;
        int[] left = new int [ n + 1 ];
        int[] right = new int [ n + 1 ];
        Arrays.fill ( left, e );
        Arrays.fill ( right, e );
        for ( int i = 0; i < n; i++ ) {
            left [ i + 1 ] = gcd ( left [ i ], array [ i ] );
        }
        for ( int i = n - 1; i >= 0; i-- ) {
            right [ i ] = gcd ( right [ i + 1 ], array [ i ] );
        }
        return left;
    }
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = Integer.parseInt ( sc.next ( ) );
        int[] a = new int [ n ];
        for ( int i = 0; i < n; i++ ) {
            a [ i ] = Integer.parseInt ( sc.next ( ) );
        }
        int[] left = ruiseki_lr ( a );
        int ans = 0;
        for ( int i = 0; i < n; i++ ) {
            ans = Math.max ( gcd ( left [ i ], right [ i + 1 ] ), ans );
        }
        System.out.println ( ans );
    }
}
