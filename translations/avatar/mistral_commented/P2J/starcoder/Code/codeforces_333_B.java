// Take input as two integers n and m from the user
Scanner I = new Scanner(System.in);
int n = I.nextInt();
int m = I.nextInt();

// Initialize a list 'b' of length 2 * n with all elements as 1
int[] b = new int[2*n];
Arrays.fill(b, 1);

// Set the first, last and middle elements of the list 'b' to 0
b[0] = b[n-1] = b[n] = b[2*n-1] = 0;

// Iterate through the given'm' pairs of row and column indices
for (int i = 0; i < m; i++) {
    // Take row and column indices as input
    int r = I.nextInt();
    int c = I.nextInt();
    
    // Set the elements at the given row and column indices to 0 in the list 'b'
    b[r-1] = b[n+c-1] = 0;
}

// Check if n is odd and if the middle two elements of the list 'b' are 1, then set the middle element to 0
if (n % 2 == 1 && b[n/2] == 1 && b[n+n/2] == 1) b[n/2] = 0;

// Calculate and print the sum of all elements in the list 'b'
System.out.println(Arrays.stream(b).sum());

