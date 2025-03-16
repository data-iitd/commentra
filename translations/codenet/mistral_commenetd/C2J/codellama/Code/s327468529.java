
// <START-OF-CODE>

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
	public static void main (String[] args) throws java.lang.Exception {
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
		    int n = sc.nextInt();
		    int m = sc.nextInt();
		    int k = sc.nextInt();
		    int q = sc.nextInt();
		    int[] a = new int[n];
		    int[] b = new int[m];
		    int[] c = new int[m];
		    int[] d = new int[m];
		    int[] e = new int[m];
		    int[] f = new int[m];
		    for(int i=0;i<n;i++){
		        a[i] = sc.nextInt();
		    }
		    for(int i=0;i<m;i++){
		        b[i] = sc.nextInt();
		        c[i] = sc.nextInt();
		        d[i] = sc.nextInt();
		        e[i] = sc.nextInt();
		        f[i] = sc.nextInt();
		    }
		    int[][] table = new int[k][k];
		    for(int i=0;i<k;i++){
		        for(int j=0;j<k;j++){
		            table[i][j] = sc.nextInt();
		        }
		    }
		    int[][] dp = new int[n+1][m+1];
		    for(int i=0;i<n+1;i++){
		        for(int j=0;j<m+1;j++){
		            dp[i][j] = -1;
		        }
		    }
		    int ans = 0;
		    for(int i=0;i<n;i++){
		        for(int j=0;j<m;j++){
		            if(a[i]==b[j]){
		                dp[i][j] = 1;
		            }
		            else{
		                dp[i][j] = 0;
		            }
		        }
		    }
		    for(int i=1;i<n+1;i++){
		        for(int j=1;j<m+1;j++){
		            if(dp[i][j]==-1){
		                dp[i][j] = dp[i-1][j]+dp[i][j-1];
		            }
		        }
		    }
		    for(int i=0;i<n;i++){
		        for(int j=0;j<m;j++){
		            if(dp[i][j]==1){
		                ans++;
		            }
		        }
		    }
		    System.out.println(ans);
		}
	}
}

// 