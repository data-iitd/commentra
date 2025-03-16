public class Main {
    public static void main(String[] args) {
        int A, B, C, D, m = 998244353;
        String[] input = System.console().readLine().split(" ");
        A = Integer.parseInt(input[0]);
        B = Integer.parseInt(input[1]);
        C = Integer.parseInt(input[2]);
        D = Integer.parseInt(input[3]);

        // Initialize a 2D array d with dimensions (C+1) x (D+1), filled with zeros
        int[][] d = new int[C + 1][D + 1];

        // Set the starting point for our calculations
        d[A][B] = 1;

        // Iterate over the range from A to C for the rows and from B to D for the columns
        for (int i = A; i <= C; i++) {
            for (int j = B; j <= D; j++) {
                // Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
                d[i][j] = (d[i][j] + (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1))) % m;
            }
        }

        // Print the value at the bottom-right corner of the array
        System.out.println(d[C][D]);
    }
}
