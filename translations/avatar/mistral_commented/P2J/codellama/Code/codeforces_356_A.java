#######
# Code
#######

// Define the number of nodes 'n' and the number of edges 'm'
int n, m;
n = sc.nextInt();
m = sc.nextInt();

// Initialize an output list 'out' of size 'n' with zeros
int[] out = new int[n];

// Initialize a complement list 'comp' of size 'n' with values 'i+2' for 'i' in range(n)
int[] comp = new int[n];
for (int i = 0; i < n; i++) {
    comp[i] = i + 2;
}

// Process each edge in the given 'm' edges
for (int i = 0; i < m; i++) {
    // Read the left node 'l', right node 'r', and value 'x' of the current edge
    int l = sc.nextInt();
    int r = sc.nextInt();
    int x = sc.nextInt();
    
    // Set the initial index 't' to the left node 'l'
    int t = l;
    
    // Iterate through the nodes from 'l' to 'r'
    while (t <= r) {
        // Get the next value in the complement list 'comp'
        int next_val = comp[t - 1];
        
        // If the current node 't' in the output list 'out' is zero and it's not the value 'x'
        if (out[t - 1] == 0 && t != x) {
            // Update the output list 'out' with the value 'x' at index 't-1'
            out[t - 1] = x;
        }
        
        // Update the complement list 'comp' with the next value or the value 'x' depending on the condition
        comp[t - 1] = r + 1 < x ? r + 1 : x;
        
        // Update the index 't' to the next value in the complement list 'comp'
        t = next_val;
    }
}

// Print the output list 'out'
for (int i = 0; i < n; i++) {
    System.out.print(out[i] + " ");
}

// End of code
