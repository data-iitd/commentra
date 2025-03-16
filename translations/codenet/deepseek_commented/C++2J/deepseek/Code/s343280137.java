public class Main {
    public static void main(String[] args) {
        // Step 1: Input Reading
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = scanner.nextInt();

        // Step 2: Array Initialization
        int[] x = new int[n + 1];
        int[] v = new int[n + 1];

        // Step 3: Reading Positions and Values
        for (int i = 1; i < n + 1; i++) {
            x[i] = scanner.nextInt();
            v[i] = scanner.nextInt();
        }

        // Step 4: Calculate Total Value Moving Left
        long[] lefttotal = new long[n + 1];
        long[] maxlefttotal = new long[n + 1];
        for (int i = 1; i < n + 1; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
        }

        // Step 5: Calculate Maximum Value Left
        for (int i = 1; i < n + 1; i++) {
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        // Step 6: Calculate Total Value Moving Right
        long[] righttotal = new long[n + 1];
        long[] maxrighttotal = new long[n + 1];
        for (int i = 1; i < n + 1; i++) {
            righttotal[i] = righttotal[i - 1] + v[n - i + 1];
        }

        // Step 7: Calculate Maximum Value Right
        for (int i = 1; i < n + 1; i++) {
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[n + 1 - i]));
        }

        // Step 8: Calculate the Maximum Value
        long ans = 0;
        for (int i = 1; i < n + 1; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]);
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]);
            ans = Math.max(ans, righttotal[i] - (c - x[n + 1 - i]));
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]);
        }

        // Step 9: Output the Result
        System.out.println(ans);
    }
}
