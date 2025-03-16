
import java.util.Scanner;

public class s257493016{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int N = scanner.nextInt();
    int[] dp = new int[H + 10001];
    for (int l = 1; l < H + 10001; l++) {
      dp[l] = 2100000000;
    }
    int amax = 0;
    for (int i = 0; i < N; i++) {
      int A = scanner.nextInt();
      int B = scanner.nextInt();
      if (A >= amax) {
        amax = A;
      }
      dp[A] = Math.min(dp[A], B);
      for (int j = A + 1; j <= H + A + 1; j++) {
        dp[j] = Math.min(dp[j], dp[j - A] + B);
      }
    }
    int min = Integer.MAX_VALUE;
    for (int i = H; i <= H + amax; i++) {
      min = Math.min(min, dp[i]);
    }
    System.out.println(min);
  }
}
