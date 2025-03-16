import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int q = sc.nextInt ( );
        int [ ] ans = new int [ 2 ];
        int [ ] p1 = new int [ ], p2 = new int [ ];
        Arrays.sort ( p1 );
        Arrays.sort ( p2 );
        int sum_b = 0, sum_p1 = 0, sum_p2 = 0;
        for ( int i = 0 ; i < q ; i ++ ) {
            int [ ] ql = new int [ 3 ];
            ql [ 0 ] = sc.nextInt ( );
            ql [ 1 ] = sc.nextInt ( );
            ql [ 2 ] = sc.nextInt ( );
            if ( ql [ 0 ] == 2 ) {
                if ( p1.length == p2.length ) {
                    ans [ 0 ] = - p2 [ 0 ];
                    ans [ 1 ] = sum_p1 - p1.length * - p2 [ 0 ] + p2.length * - p2 [ 0 ] - sum_p2 + sum_b;
                } else {
                    ans [ 0 ] = p1 [ 0 ];
                    ans [ 1 ] = sum_p1 - p1.length * p1 [ 0 ] + p2.length * p1 [ 0 ] - sum_p2 + sum_b;
                }
                System.out.println ( ans [ 0 ] + " " + ans [ 1 ] );
            } else {
                sum_b += ql [ 2 ];
                if ( p1.length == 0 ) {
                    p1 [ 0 ] = ql [ 1 ];
                    sum_p1 += ql [ 1 ];
                } else if ( p1 [ 0 ] <= ql [ 1 ] ) {
                    p1 [ 0 ] = ql [ 1 ];
                    sum_p1 += ql [ 1 ];
                } else {
                    p2 [ 0 ] = - ql [ 1 ];
                    sum_p2 += ql [ 1 ];
                }
                Arrays.sort ( p1 );
                Arrays.sort ( p2 );
                if ( p1.length - 1 > p2.length ) {
                    int k = p1 [ 0 ];
                    p1 [ 0 ] = p2 [ 0 ];
                    p2 [ 0 ] = - k;
                    sum_p1 -= k;
                    sum_p2 += k;
                }
            }
        }
    }
}
