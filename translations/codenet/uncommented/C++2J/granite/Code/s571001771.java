
import java.util.*;
import java.io.*;
class s571001771{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    long[] key = new long[m];
    long[] cost = new long[m];
    long[][] dp = new long[(1<<12)+5][m+1];
    for(int i=0;i<(1<<12)+5;i++){
      for(int j=0;j<m+1;j++){
        dp[i][j] = Long.MAX_VALUE;
      }
    }
    dp[0][0] = 0;
    for(int i=1;i<=m;i++){
      cost[i] = sc.nextLong();
      int b = sc.nextInt();
      for(int j=0;j<b;j++){
        int c = sc.nextInt();
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
