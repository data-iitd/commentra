// Get the number of nodes 'n' and the number of edges 'k' from user input
Scanner u = new Scanner(System.in);
int n = u.nextInt();
int k = u.nextInt();

// Initialize an empty list 'M' of size 'n' to represent the status of each node
int[] M = new int[n];

// Initialize a counter'm' to keep track of the number of nodes printed
int m = 0;

// Iterate through each node 'j' in the range of 0 to 'n'
for (int j = 0; j < n; j++) {
    // Iterate through each node 'p' in the range of 0 to 'n'
    for (int p = 0; p < n; p++) {
        // Check if the current node 'p' is not yet processed (M[p] == 0)
        if (M[p] == 0) {
            // Print the index of the current node 'p' and increment the counter'm'
            System.out.print(p + 1 + " ");
            m++;
            break;
        }
    }
    // Decrement the status of all nodes 'l' in the range of 0 to 'p' (exclusive)
    for (int l = 0; l < p - k; l++) {
        M[l]--;
    }
    // Decrement the status of the current node 'p'
    M[p]--;
}

