#######
# Code
#######

// Read the first line of input containing the number of nodes 'n' and edges'm'
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize a list 'p' of numbers from 1 to 'n'
List<Integer> p = new ArrayList<>();
for (int i = 1; i <= n; i++) {
    p.add(i);
}

// Read the second line of input containing the heights of the nodes
List<Integer> h = new ArrayList<>();
for (int i = 0; i < n; i++) {
    h.add(sc.nextInt());
}

// Create a dictionary 'hp' using list comprehension to store node number as key and height as value
Map<Integer, Integer> hp = new HashMap<>();
for (int i = 0; i < n; i++) {
    hp.put(p.get(i), h.get(i));
}

// Initialize an empty dictionary 'path' to store the graph
Map<Integer, List<Integer>> path = new HashMap<>();
for (int i = 1; i <= n; i++) {
    path.put(i, new ArrayList<>());
}

// Read'm' lines of input containing edges and add them to the 'path' dictionary
for (int i = 0; i < m; i++) {
    int a = sc.nextInt();
    int b = sc.nextInt();
    path.get(a).add(b);
    path.get(b).add(a);
}

// Initialize a counter 'c' to store the number of valid paths
int c = 0;

// Iterate through each node in the graph and check if it forms a valid path
for (int i = 1; i <= n; i++) {
    // Initialize a flag 'f' to check if the current node is a valid starting point
    boolean f = false;
    // Iterate through each neighbor of the current node and check if it is a valid ending point
    for (int j : path.get(i)) {
        // If the height of the current node is less than or equal to the height of its neighbor,
        // then it is not a valid path and we set the flag 'f' to 1 and break the loop
        if (hp.get(i) <= hp.get(j)) {
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
System.out.println(c);

