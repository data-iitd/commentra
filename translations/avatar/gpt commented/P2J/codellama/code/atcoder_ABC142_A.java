
// Function to read a single integer from input
static int nextInt() {
    return Integer.parseInt(input.nextLine());
}

// Function to read a list of integers from input
static int[] nextInts() {
    String[] temp = input.nextLine().split(" ");
    int[] ints = new int[temp.length];
    for (int i = 0; i < temp.length; i++) {
        ints[i] = Integer.parseInt(temp[i]);
    }
    return ints;
}

// Read the number of iterations or elements
int n = nextInt();

// Initialize a counter for odd indices
int t = 0;

// Loop through the range of n
for (int i = 0; i < n; i++) {
    // Check if the current index (i + 1) is odd
    if ((i + 1) % 2 == 1) {
        t++;  // Increment the counter for odd indices
    }
}

// Calculate and print the ratio of odd indices to total elements
System.out.println(t / (double) n);

