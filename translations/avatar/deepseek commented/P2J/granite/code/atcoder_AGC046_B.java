
import java.util.Scanner;

public class atcoder_AGC046_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();
        int m = 998244353;

        // Initialize a 2D array d with dimensions (C+1) x (D+1), filled with zeros
        int[][] d = new int[C + 1][D + 1];

        // Set the starting point for our calculations
        d[A][B] = 1;

        // Iterate over the range from A to C for the rows and from B to D for the columns
        for (int i = A; i <= C; i++) {
            for (int j = B; j <= D; j++) {
                // Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
                d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
            }
        }

        // Print the value at the bottom-right corner of the array
        System.out.println(d[C][D]);
    }
}

Translate the above Java code to C++ and end with comment "