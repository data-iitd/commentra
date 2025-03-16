import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int [ ] [ ] ls_xyh = new int [ n ] [ 3 ];
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < 3 ; j ++ ) {
                ls_xyh [ i ] [ j ] = sc.nextInt ( );
            }
        }
        System.out.println ( solve ( n, ls_xyh ) );
    }
    public static String solve ( int n, int [ ] [ ] ls_xyh ) {
        int x0 = 0, y0 = 0, h0 = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( ls_xyh [ i ] [ 2 ] > 0 ) {
                x0 = ls_xyh [ i ] [ 0 ];
                y0 = ls_xyh [ i ] [ 1 ];
                h0 = ls_xyh [ i ] [ 2 ];
                break;
            }
        }
        List < Integer > [ ] cands = new ArrayList < > [ 101 * 101 ];
        for ( int i = 0 ; i < 101 ; i ++ ) {
            for ( int j = 0 ; j < 101 ; j ++ ) {
                cands. add ( new ArrayList < > ( ) );
                cands. get ( i * 101 + j ). add ( i );
                cands. get ( i * 101 + j ). add ( j );
                cands. get ( i * 101 + j ). add ( h0 + Math.max ( Math.abs ( i - x0 ), Math.abs ( j - y0 ) ) );
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            int [ ] xyh = ls_xyh [ i ];
            for ( int j = 0 ; j < 101 * 101 ; j ++ ) {
                int [ ] cand = cands. get ( j );
                int cx = cand. get ( 0 );
                int cy = cand. get ( 1 );
                int ch = cand. get ( 2 );
                if ( Math.max ( ch - Math.max ( Math.abs ( cx - xyh [ 0 ] ), Math.abs ( cy - xyh [ 1 ] ) ), 0 )!= xyh [ 2 ] ) {
                    cands. remove ( j );
                    j --;
                }
            }
        }
        int [ ] cand = cands. get ( 0 );
        int xx = cand. get ( 0 );
        int yy = cand. get ( 1 );
        int hh = cand. get ( 2 );
        return xx + " " + yy + " " + hh;
    }
}
