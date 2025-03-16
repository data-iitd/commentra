
import java.util.*;
import java.io.*;

class s571001771 {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] nm = br.readLine().split(" ");
    int n = Integer.parseInt(nm[0]);
    int m = Integer.parseInt(nm[1]);
    long[] key = new long[m+1];
    long[] cost = new long[m+1];
    long[][] dp = new long[(1<<12)+5][m+1];
    for(int i=0;i<(1<<12)+5;i++){
      for(int j=0;j<m+1;j++){
        dp[i][j] = Long.MAX_VALUE;
      }
    }
    dp[0][0] = 0;
    for(int i=1;i<=m;i++){
      String[] bc = br.readLine().split(" ");
      cost[i] = Long.parseLong(bc[0]);
      int b = Integer.parseInt(bc[1]);
      for(int j=0;j<b;j++){
        int c = Integer.parseInt(br.readLine());
        key[i] += (1<<(c-1));
      }
    }
    for(int i=0;i<(1<<n);i++){
      for(int j=0;j<m;j++){
        dp[i][j+1] = Math.min(dp[i][j],dp[i][j+1]);
        dp[i|key[j+1]][j+1] = Math.min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]);
      }
    }
    if(dp[(1<<n)-1][m]==Long.MAX_VALUE)System.out.println(-1);
    else System.out.println(dp[(1<<n)-1][m]);
  }
}

Translate the above Java code to Python and end with comment "