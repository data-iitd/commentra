public class GameWinner {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[100];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        boolean[] dp = new boolean[k + 1];
        for (int i = 1; i <= k; i++) {
            boolean win = false;
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (!dp[i - a[j]]) {
                    win = true;
                }
            }
            dp[i] = win;
        }
        System.out.println(dp[k] ? "First" : "Second");
    }
}
