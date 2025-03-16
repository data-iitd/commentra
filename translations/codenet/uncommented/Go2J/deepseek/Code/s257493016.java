public class Main {
    public static int min(int... n) {
        if (n.length == 0) {
            throw new IllegalArgumentException("len == 0");
        }
        int r = n[0];
        for (int i = 1; i < n.length; i++) {
            if (n[i] <= r) {
                r = n[i];
            }
        }
        return r;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
        int[] dpHtoAmax = new int[amax + 1];
        System.arraycopy(dp, H, dpHtoAmax, 0, amax + 1);
        System.out.println(min(dpHtoAmax));
    }
}
