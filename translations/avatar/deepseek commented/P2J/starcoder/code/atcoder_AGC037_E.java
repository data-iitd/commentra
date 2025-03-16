
import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int K = sc.nextInt ( );
        String S = sc.next ( );
        boolean aaaa = false;
        if ( K >= 15 ) {
            aaaa = true;
        } else if ( Math.pow ( 2, K ) >= N ) {
            aaaa = true;
        }
        if ( aaaa ) {
            System.out.println ( S.charAt ( 0 ) * N );
            return;
        }
        String U = S + new StringBuilder ( S ).reverse ( ).toString ( );
        char c = S.charAt ( 0 );
        int p = U.indexOf ( c );
        int minindex = p;
        p += 1;
        while ( p <= N ) {
            if ( U.charAt ( p ) == c ) {
                if ( check_normal_dict ( U, minindex, p ) ) {
                    minindex = p;
                }
            }
            p += 1;
        }
        String ans = U.substring ( minindex, minindex + N );
        if ( K == 1 ) {
            System.out.println ( ans );
        } else {
            int count = 0;
            for ( int i = 0 ; i < N ; i ++ ) {
                if ( ans.charAt ( i ) == ans.charAt ( 0 ) ) {
                    count += 1;
                } else {
                    break;
                }
            }
            if ( count * ( int ) Math.pow ( 2, K - 1 ) >= N ) {
                System.out.println ( ans.charAt ( 0 ) * N );
            } else {
                ans = ans.charAt ( 0 ) * ( count * ( int ) Math.pow ( 2, K - 1 ) - 1 ) + ans;
                System.out.println ( ans.substring ( 0, N ) );
            }
        }
    }
    public static boolean check_normal_dict ( String u, int pointer1, int pointer2 ) {
        for ( int i = 0 ; i < N ; i ++ ) {
            if ( u.charAt ( pointer1 + i ) > u.charAt ( pointer2 + i ) ) {
                return true;
            } else if ( u.charAt ( pointer1 + i ) < u.charAt ( pointer2 + i ) ) {
                return false;
            }
        }
        return false;
    }
}

