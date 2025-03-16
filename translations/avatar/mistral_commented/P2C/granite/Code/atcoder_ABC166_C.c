
###
# Code
###

# Read the first line of input containing the number of nodes 'n' and edges'm'
# and store them in variables 'n' and'm' respectively
int n, m;
scanf("%d %d", &n, &m);

// Initialize an array 'p' of size 'n' to store the node numbers
int p[n];

// Read the second line of input containing the heights of the nodes
// and store them in the array 'p'
for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
}

// Create a dictionary 'hp' using a struct to store node number as key and height as value
struct Node {
    int key;
    int value;
};
struct Node hp[n];
for (int i = 0; i < n; i++) {
    hp[i].key = i;
    hp[i].value = p[i];
}

// Initialize a dictionary 'path' using a struct to store the graph
struct Edge {
    int from;
    int to;
};
struct Edge path[m];

// Read'm' lines of input containing edges and add them to the 'path' dictionary
for (int i = 0; i < m; i++) {
    scanf("%d %d", &path[i].from, &path[i].to);
}

// Initialize a counter 'c' to store the number of valid paths
int c = 0;

// Iterate through each node in the graph and check if it forms a valid path
for (int i = 0; i < n; i++) {
    // Initialize a flag 'f' to check if the current node is a valid starting point
    int f = 0;
    // Iterate through each neighbor of the current node and check if it is a valid ending point
    for (int j = 0; j < m; j++) {
        if (path[j].from == i) {
            if (hp[i].value <= hp[path[j].to].value) {
                f = 1;
                break;
            }
        }
    }
    // If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
    // and we increment the counter 'c'
    if (f == 0) {
        c++;
    }
}

// Print the final result, i.e., the number of valid paths
printf("%d\n", c);

