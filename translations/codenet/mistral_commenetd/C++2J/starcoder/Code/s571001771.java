import java.util.*;
import java.io.*;
public class Main{
  public static void main(String[] args) throws Exception{
    // Read input
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int m=sc.nextInt();
    int[] key=new int[m+5];
    int[] cost=new int[m+5];
    int[][] dp=new int[(1<<12)+5][m+5];
    for(int i=0;i<(1<<12)+5;i++){
      for(int j=0;j<m+5;j++){
        dp[i][j]=Integer.MAX_VALUE;
      }
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
      int b=sc.nextInt();
      cost[i]=sc.nextInt();
      for(int j=0;j<b;j++){
        int c=sc.nextInt();
        key[i]+=(1<<(c-1));
      }
    }
    for(int i=0;i<(1<<n);i++){
      for(int j=0;j<m;j++){
        dp[i][j+1]=Math.min(dp[i][j],dp[i][j+1]);
        dp[i|key[j+1]][j+1]=Math.min(dp[i|key[j+1]][j+1],dp[i][j]+cost[j+1]);
      }
    }
    if(dp[(1<<n)-1][m]==Integer.MAX_VALUE)System.out.println("-1");
    else System.out.println(dp[(1<<n)-1][m]);
  }
}

