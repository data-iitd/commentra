#######
# Code
#######

// Read input as two integers n and m
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int m = scanner.nextInt();

// Check if both n and m are less than 1
if (n < 1) {
    // If yes, print n and m and quit the program
    if (m < 1) {
        System.out.println(n + " " + m);
        return;
    }
    // If not, print "Impossible" and quit the program
    System.out.println("Impossible");
    return;
}

// Check if m is greater than n
if (m > n) {
    // If yes, calculate the minimum and maximum values
    int min = m;
    int max = n + m - 1;
    // Print the minimum and maximum values
    System.out.println(min + " " + max);
}

// If m is less than or equal to n
if (m <= n) {
    // Calculate the minimum and maximum values
    int min = n;
    int max = n + m - 1;
    // If m is 0, adjust the maximum value accordingly
    if (m == 0) {
        max = n;
    }
    // Print the minimum and maximum values
    System.out.println(min + " " + max);
}

