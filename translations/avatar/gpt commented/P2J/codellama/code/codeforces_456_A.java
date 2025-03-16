// Read the number of rows (n) from user input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read n rows of integers into a 2D array (matrix) m
int[][] m = new int[n][2];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
        m[i][j] = sc.nextInt();
    }
}

// Sort the matrix m in descending order based on the first element of each row
Arrays.sort(m, (a, b) -> b[0] - a[0]);

// Initialize a variable a with the first row of the sorted matrix
int[] a = m[0];

// Iterate through the remaining rows of the sorted matrix
for (int i = 1; i < n; i++) {
    // Check if the second element of the current row is greater than the second element of the previous row
    if (m[i][1] > a[1]) {
        // If true, print 'Happy Alex' and exit the loop
        System.out.println("Happy Alex");
        break;
    }
    // Update a to the current row for the next iteration
    a = m[i];
}
else {
    // If the loop completes without finding a greater second element, print 'Poor Alex'
    System.out.println("Poor Alex");
}

