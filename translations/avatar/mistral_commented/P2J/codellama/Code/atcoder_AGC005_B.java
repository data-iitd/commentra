
// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
public static int root(int x) {
    return x == par[x] ? x : root(par[x]);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
public static boolean same(int x, int y) {
    return root(x) == root(y);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
public static void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x] += 1;
            }
        }
    }
}

// Read input from standard input and initialize variables
int n = sc.nextInt();
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Initialize parent and rank lists with given size
int[] par = new int[n];
int[] rank = new int[n];
int[] size = new int[n];
for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 1;
    size[i] = 1;
}

// Initialize a list b to store the indices of elements in the input list a
int[] b = new int[n];
for (int i = 0; i < n; i++) {
    b[a[i] - 1] = i;
}

// Initialize a variable c to store the result
long c = 0;

// Iterate through the list b from the second element to the first
for (int k = b.length - 1; k >= 0; k--) {
    // Initialize variables l and r to store the sizes of the left and right subtrees
    long l = 1;
    long r = 1;

    // Check if the current node k has a larger element to its left
    if (k > 0 && a[k - 1] > a[k]) {
        // If yes, update l with the size of the left subtree
        l += size[root(k - 1)];
        // Merge the left and current subtrees
        unite(k - 1, k);
    }

    // Check if the current node k has a larger element to its right
    if (k + 1 < n && a[k + 1] > a[k]) {
        // If yes, update r with the size of the right subtree
        r += size[root(k + 1)];
        // Merge the right and current subtrees
        unite(k + 1, k);
    }

    // Update the result variable c with the product of the sizes of the left and right subtrees
    // and the value of the current element
    c += l * r * a[k];
}

// Print the result
System.out.println(c);

