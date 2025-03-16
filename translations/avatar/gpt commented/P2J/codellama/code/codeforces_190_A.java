// Read two integers n and m from input
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int m = scanner.nextInt();

// Check if n is less than 1
if (n < 1) {
    // If n is less than 1, check if m is also less than 1
    if (m < 1) {
        // If both n and m are less than 1, print their values and exit
        System.out.println(n + " " + m);
        return;
    }
    // If only n is less than 1 and m is greater than or equal to 1, print "Impossible"
    System.out.println("Impossible");
    return;
}

// If m is greater than n, calculate min and max values
if (m > n) {
    int min = m;  // Set min to m
    int max = n + m - 1;  // Calculate max based on n and m
    System.out.println(min + " " + max);  // Print the calculated min and max values
}

// If m is less than or equal to n, calculate min and max values
if (m <= n) {
    int min = n;  // Set min to n
    int max = n + m - 1;  // Calculate max based on n and m
    if (m == 0) {
        max = n;  // If m is 0, set max to n
    }
    System.out.println(min + " " + max);  // Print the calculated min and max values
}

