// Read input from the user
Scanner sc = new Scanner(System.in);

// Read the values of n and m from input, where n is the size of the array and m is the number of blocked cells
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize a list b of size 2*n with all elements set to 1
// This list will represent the state of the cells (1 for unblocked, 0 for blocked)
int[] b = new int[2 * n];
Arrays.fill(b, 1);

// Set specific positions in the list b to 0 to indicate they are blocked
// The first and last elements of the first half and the last half are blocked
b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

// Process each blocked cell based on user input
for (int i = 0; i < m; i++) {
    // Read the row (r) and column (c) of the blocked cell
    int r = sc.nextInt();
    int c = sc.nextInt();
    // Mark the corresponding positions in the list b as blocked (0)
    b[r - 1] = b[n + c - 1] = 0;
}

// If n is odd and the middle cells are unblocked, block them
if (n % 2 == 0 && b[n / 2] == 1 && b[n + n / 2] == 1) {
    b[n / 2] = 0;
}

// Output the total number of unblocked cells by summing the list b
int sum = 0;
for (int i = 0; i < b.length; i++) {
    sum += b[i];
}
System.out.println(sum);

