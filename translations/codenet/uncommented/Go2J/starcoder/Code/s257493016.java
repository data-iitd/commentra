import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int N = sc.nextInt();
    int[] dp = new int[H+10001];
    int amax = 0;
    for (int i = 0; i < N; i++) {
      int A = sc.nextInt();
      int B = sc.nextInt();
      if (A >= amax) {
        amax = A;
      }
      dp[A] = Math.min(dp[A], B);
      for (int j = A+1; j <= H+A+1; j++) {
        dp[j] = Math.min(dp[j], dp[j-A] + B);
      }
    }
    System.out.println(Arrays.stream(dp).limit(H+amax+1).min().getAsInt());
  }
}

