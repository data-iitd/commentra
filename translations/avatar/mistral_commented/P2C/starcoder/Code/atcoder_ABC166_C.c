#######
# Code
#######

# Read the first line of input containing the number of nodes 'n' and edges'm'
scanf("%d %d", &n, &m);

// Initialize a list 'p' of numbers from 1 to 'n'
int p[n];
for (int i = 0; i < n; i++) {
    p[i] = i + 1;
}

// Read the second line of input containing the heights of the nodes
int h[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
}

// Create a dictionary 'hp' using list comprehension to store node number as key and height as value
int hp[n];
for (int i = 0; i < n; i++) {
    hp[p[i] - 1] = h[i];
}

// Initialize an empty dictionary 'path' to store the graph
int path[n][n];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        path[i][j] = 0;
    }
}

// Read'm' lines of input containing edges and add them to the 'path' dictionary
for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    path[a - 1][b - 1] = 1;
    path[b - 1][a - 1] = 1;
}

// Initialize a counter 'c' to store the number of valid paths
int c = 0;

// Iterate through each node in the graph and check if it forms a valid path
for (int i = 0; i < n; i++) {
    // Initialize a flag 'f' to check if the current node is a valid starting point
    int f = 0;
    // Iterate through each neighbor of the current node and check if it is a valid ending point
    for (int j = 0; j < n; j++) {
        // If the height of the current node is less than or equal to the height of its neighbor,
        // then it is not a valid path and we set the flag 'f' to 1 and break the loop
        if (hp[i] <= hp[j]) {
            f = 1;
            break;
        }
    }
    // If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
    // and we increment the counter 'c'
    if (f == 0) {
        c++;
    }
}

// Print the final result, i.e., the number of valid paths
printf("%d", c);

