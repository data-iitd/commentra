import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int [ ] nums = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ )
            nums [ i ] = sc.nextInt ( ) - 1;
        boolean noOne = false;
        if ( nums [ 0 ]!= 0 ) {
            for ( int i = 0 ; i < n ; i ++ )
                nums [ i ] /= 2;
            noOne = true;
        }
        boolean isOdd = false;
        for ( int i = 0 ; i < n ; i ++ )
            if (!parityOfNcr ( n - 1, i ) && ( nums [ i ] & 1 )!= 0 )
                isOdd ^= true;
        if (!isOdd )
            System.out.println ( 0 );
        else
            System.out.println ( 1 << noOne );
    }
    public static boolean parityOfNcr ( int n, int r ) {
        int f = 0;
        for ( int i = 1 ; i <= n ; i ++ )
            f += ( n - i + 1 ) / i;
        return f - ( n - r + 1 ) / r - r > 0;
    }
}
