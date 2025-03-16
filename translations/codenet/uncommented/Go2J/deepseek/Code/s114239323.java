public class Main {
    public static void main(String[] args) {
        // Read input
        int N = nextInt();
        int[] h = nextInts(N);
        
        // Initialize dp array
        int[] dp = new int[N];
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
        }
        dp[1] = Math.abs(h[0] - h[1]);
        
        // Fill dp array
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]),
                             dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }
        
        // Output result
        System.out.println(dp[N - 1]);
    }
    
    // Helper methods for reading input
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);
    
    public static int nextInt() {
        return scanner.nextInt();
    }
    
    public static int[] nextInts(int n) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = scanner.nextInt();
        }
        return r;
    }
}
