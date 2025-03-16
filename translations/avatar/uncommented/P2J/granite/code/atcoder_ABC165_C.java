
import java.util.*;
class atcoder_ABC165_C {
    static int res = 0;
    public static void solve ( int N, int M, int Q, int[] a, int[] b, int[] c, int[] d ) {
        rec ( new ArrayList < Integer > ( ), N, M, Q, a, b, c, d ) ;
        System.out.println ( res ) ;
    }
    public static void rec ( List < Integer > A, int N, int M, int Q, int[] a, int[] b, int[] c, int[] d ) {
        if ( A. size ( ) == N ) {
            int ans = 0 ;
            for ( int i = 0 ; i < Q ; i ++ ) {
                if ( A. get ( b [ i ] - 1 ) - A. get ( a [ i ] - 1 ) == c [ i ] ) {
                    ans += d [ i ] ;
                }
            }
            res = Math. max ( res, ans ) ;
            return ;
        }
        int last_max = 1 ;
        if ( A. size ( )!= 0 ) {
            last_max = A. get ( A. size ( ) - 1 ) ;
        }
        for ( int i = last_max ; i <= M ; i ++ ) {
            A. add ( i ) ;
            rec ( A, N, M, Q, a, b, c, d ) ;
            A. remove ( A. size ( ) - 1 ) ;
        }
    }
    public static void main ( String[] args ) {
        Scanner in = new Scanner ( System. in ) ;
        int N = in.nextInt ( ) ;
        int M = in.nextInt ( ) ;
        int Q = in.nextInt ( ) ;
        int[] a = new int [ Q ] ;
        int[] b = new int [ Q ] ;
        int[] c = new int [ Q ] ;
        int[] d = new int [ Q ] ;
        for ( int i = 0 ; i < Q ; i ++ ) {
            a [ i ] = in.nextInt ( ) ;
            b [ i ] = in.nextInt ( ) ;
            c [ i ] = in.nextInt ( ) ;
            d [ i ] = in.nextInt ( ) ;
        }
        solve ( N, M, Q, a, b, c, d ) ;
    }
}
