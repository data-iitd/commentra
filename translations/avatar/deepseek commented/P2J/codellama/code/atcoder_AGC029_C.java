
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[] dp = new int[n];
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] <= dp[i - 1]) {
                dp[i] = arr[i];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        System.out.println(max);
    }
}

