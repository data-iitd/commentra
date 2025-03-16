// Read input values A, B, C, D and convert them to integers
Scanner scanner = new Scanner(System.in);
int A = scanner.nextInt();
int B = scanner.nextInt();
int C = scanner.nextInt();
int D = scanner.nextInt();

// Define a large prime number for modulo operations
int m = 998244353;

// Initialize a 2D list (matrix) d with dimensions (C+1) x (D+1) filled with zeros
int[][] d = new int[C + 1][D + 1];

// Set the starting point in the matrix d at position (A, B) to 1
d[A][B] = 1;

// Iterate over the range from A to C (inclusive) for the first dimension
for (int i = A; i <= C; i++) {
    // Iterate over the range from B to D (inclusive) for the second dimension
    for (int j = B; j <= D; j++) {
        // Update the current cell d[i][j] using the values from the previous cells
        d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
    }
}

// Output the final result from the bottom-right corner of the matrix d
System.out.println(d[C][D]);

