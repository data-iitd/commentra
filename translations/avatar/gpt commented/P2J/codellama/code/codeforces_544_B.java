// Read two integers n and k from input
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int k = scanner.nextInt();

// Initialize a counter to keep track of the number of 'L' printed
int x = 0;

// Check if k is less than or equal to the maximum number of 'L' that can be printed
if (k <= Math.max(n * n / 2, n * n - (n * n / 2))) {
    // If the condition is satisfied, print 'YES'
    System.out.println("YES");
    
    // Iterate over each row of the n x n grid
    for (int i = 0; i < n; i++) {
        // Iterate over each column of the n x n grid
        for (int j = 0; j < n; j++) {
            // Check if the current position (i, j) is in the same parity group and if we can still print 'L'
            if (i % 2 == j % 2 && x < k) {
                // Print 'L' and increment the counter
                System.out.print("L");
                x++;
            } else {
                // Print 'S' if the conditions for 'L' are not met
                System.out.print("S");
            }
        }
        // Move to the next line after finishing a row
        System.out.println();
    }
} else {
    // If k is greater than the maximum possible 'L', print 'NO'
    System.out.println("NO");
}

