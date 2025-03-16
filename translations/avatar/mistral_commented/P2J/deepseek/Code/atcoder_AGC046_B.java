import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input variables A, B, C, D as integers
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();
        
        // Initialize a 2D array 'd' with dimensions (C+1) x (D+1)
        // filled with zeros
        int[][] d = new int[C + 1][D + 1];
        
        // Set the value of d[A][B] to 1
        d[A][B] = 1;
        
        // Matrix multiplication using dynamic programming approach
        // Iterate through the rows from A to C
        for (int i = A; i <= C; i++) {
            // Iterate through the columns from B to D
            for (int j = B; j <= D; j++) {
                // Calculate the value of d[i][j] using the previous values
                d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
            }
        }
        
        // Print the final value of d[C][D]
        System.out.println(d[C][D]);
    }
}
