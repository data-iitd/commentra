import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int k = sc.nextInt ( );
        int[] coef = new int[n];
        int[] dp = new int[k + 1][n];
        for ( int i = 1 ; i <= n ; i++ ) {
            coef[i - 1] = (n / i) - (n / (i + 1));
        }
        for ( int i = 1 ; i <= k ; i++ ) {
            for ( int j = n - 1 ; j >= 0 ; j-- ) {
                if ( j == n - 1 ) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = coef[j] * dp[i - 1][j + 1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; i++ ) {
            ans += dp[k][i];
            ans %= 1000000007;
        }
        System.out.println ( ans );
    }
}

