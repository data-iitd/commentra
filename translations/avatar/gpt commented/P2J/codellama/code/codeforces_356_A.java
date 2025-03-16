// Read the values of n and m from input, where n is the number of elements and m is the number of operations
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize an output list with zeros, which will store the final results
int[] out = new int[n];

// Create a list 'comp' that holds values from 2 to n+1 (inclusive)
int[] comp = new int[n];
for (int i = 0; i < n; i++) {
    comp[i] = i + 2;
}

// Process each of the m operations
for (int i = 0; i < m; i++) {
    // Read the values of l, r, and x for the current operation
    int l = sc.nextInt();
    int r = sc.nextInt();
    int x = sc.nextInt();
    
    // Start from the left index l
    int t = l;
    
    // Continue processing while t is within the range [l, r]
    while (t <= r) {
        // Get the next value from the 'comp' list
        int next_val = comp[t - 1];
        
        // If the current position in 'out' is still 0 and t is not equal to x
        if (out[t - 1] == 0 && t != x) {
            // Set the output at position t-1 to x
            out[t - 1] = x;
        }
        
        // Update the 'comp' list at position t-1 based on the current value of t and x
        comp[t - 1] = r + 1;
        if (t >= x) {
            comp[t - 1] = x;
        }
        
        // Move to the next index as determined by next_val
        t = next_val;
    }
}

// Print the final output list, unpacking the values to display them in a single line
for (int i = 0; i < n; i++) {
    System.out.print(out[i] + " ");
}

// End of code
