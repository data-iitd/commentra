
import java.util.Scanner;

public class s436432602{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] dp = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            boolean win = false;
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (dp[i - a[j]] == 0) {
                    win = true;
                }
            }
            dp[i] = win? 1 : 0;
        }
        System.out.println(dp[k] == 1? "First" : "Second");
    }
}

