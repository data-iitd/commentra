#######
# Code
#######

# Read the first line of input containing the number of nodes 'n' and edges'm'
cin >> n >> m;

// Initialize a list 'p' of numbers from 1 to 'n'
vector<int> p(n);
for (int i = 0; i < n; i++) {
    p[i] = i + 1;
}

// Read the second line of input containing the heights of the nodes
vector<int> h(n);
for (int i = 0; i < n; i++) {
    cin >> h[i];
}

// Create a dictionary 'hp' using list comprehension to store node number as key and height as value
unordered_map<int, int> hp;
for (int i = 0; i < n; i++) {
    hp[p[i]] = h[i];
}

// Initialize an empty dictionary 'path' to store the graph
unordered_map<int, vector<int>> path;
for (int i = 0; i < n; i++) {
    path[p[i]] = vector<int>();
}

// Read'm' lines of input containing edges and add them to the 'path' dictionary
for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
}

// Initialize a counter 'c' to store the number of valid paths
int c = 0;

// Iterate through each node in the graph and check if it forms a valid path
for (int i = 0; i < n; i++) {
    // Initialize a flag 'f' to check if the current node is a valid starting point
    bool f = false;
    // Iterate through each neighbor of the current node and check if it is a valid ending point
    for (int j = 0; j < path[p[i]].size(); j++) {
        // If the height of the current node is less than or equal to the height of its neighbor,
        // then it is not a valid path and we set the flag 'f' to 1 and break the loop
        if (hp[p[i]] <= hp[path[p[i]][j]]) {
            f = true;
            break;
        }
    }
    // If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
    // and we increment the counter 'c'
    if (f == false) {
        c++;
    }
}

// Print the final result, i.e., the number of valid paths
cout << c << endl;

