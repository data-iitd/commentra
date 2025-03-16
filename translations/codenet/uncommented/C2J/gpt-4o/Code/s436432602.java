import java.util.Scanner;

public class Game {
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[100];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] dp = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            int win = 0;
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (dp[i - a[j]] == 0) {
                    win = 1;
                }
            }
            dp[i] = win;
        }
        System.out.println(dp[k] == 1 ? "First" : "Second");
        scanner.close();
    }

    public static void main(String[] args) {
        run();
    }
}

// <END-OF-CODE>
