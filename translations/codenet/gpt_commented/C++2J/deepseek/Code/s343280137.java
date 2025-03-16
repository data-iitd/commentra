public class Main {
    public static void main(String[] args) {
        // Read the number of elements and the constant c
        int n, c;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        c = scanner.nextInt();

        // Initialize arrays to store positions and velocities
        int[] x = new int[n + 1];
        int[] v = new int[n + 1];

        // Read the positions and velocities of the elements
        for (int i = 1; i < n + 1; i++) {
            x[i] = scanner.nextInt();
            v[i] = scanner.nextInt();
        }

        // Initialize arrays to store cumulative velocities from the left
        long[] lefttotal = new long[n + 1];
        long[] maxlefttotal = new long[n + 1];

        // Calculate cumulative velocities from the left
        for (int i = 1; i < n + 1; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
        }

        // Calculate the maximum value of lefttotal adjusted by position
        for (int i = 1; i < n + 1; i++) {
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        // Initialize arrays to store cumulative velocities from the right
        long[] righttotal = new long[n + 1];
        long[] maxrighttotal = new long[n + 1];

        // Calculate cumulative velocities from the right
        for (int i = 1; i < n + 1; i++) {
            righttotal[i] = righttotal[i - 1] + v[n - i + 1];
        }

        // Calculate the maximum value of righttotal adjusted by position
        for (int i = 1; i < n + 1; i++) {
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[n + 1 - i]));
        }

        // Initialize the answer variable to store the maximum result
        long ans = 0;

        // Evaluate the maximum possible value based on different scenarios
        for (int i = 1; i < n + 1; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]); // Scenario 1
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]); // Scenario 2
            ans = Math.max(ans, righttotal[i] - (c - x[n + 1 - i])); // Scenario 3
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]); // Scenario 4
        }

        // Output the final result
        System.out.println(ans);
    }
}
