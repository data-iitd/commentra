import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        int K, N ;
        K = sc.nextInt ( ) ;
        N = sc.nextInt ( ) ;
        int[] ans = new int[2 * K + 1] ;
        ans[0] = 1 ;
        ans[1] = 1 ;
        for ( int i = 2 ; i <= 2 * K + 1 ; i++ ) {
            ans[i] = ( ans[i - 1] + ans[i - 2] ) % 998244353 ;
        }
        System.out.println ( ans[2 * K] ) ;
        for ( int i = 2 ; i <= K ; i++ ) {
            System.out.println ( ans[2 * K - i] ) ;
        }
    }
}
