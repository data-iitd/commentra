
import java.util.*;

// Define a constant for the maximum number of nodes
final int maxn = 1e5 + 5;

// Structure to represent a node with coordinates and an ID
class Node {
    int x, y, id;
}

// Structure to represent an edge with two nodes and a weight
class Edge {
    int u, v, val;
    // Overloading the less-than operator for sorting edges based on their weight
    public boolean less(Edge rhs) {
        return val < rhs.val;
    }
}

// Array to store the parent of each node for union-find
int par[] = new int[maxn];
int n; // Number of nodes

// Comparison function to sort nodes based on their x-coordinate
class cmp1 implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return a.x - b.x;
    }
}

// Comparison function to sort nodes based on their y-coordinate
class cmp2 implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return a.y - b.y;
    }
}

// Function to initialize the union-find structure
void init() {
    for (int i = 0; i <= n; i++)
        par[i] = i; // Each node is its own parent initially
}

// Function to find the representative parent of a node
int findpar(int x) {
    return par[x] = (par[x] == x ? x : findpar(par[x])); // Path compression
}

// Function to unite two nodes in the union-find structure
void unite(int x, int y) {
    x = findpar(x), y = findpar(y); // Find the parents of both nodes
    if (x == y) return; // If they are already in the same set, do nothing
    par[x] = y; // Union the sets by making one parent of the other
}

public class Main {
    public static void main(String[] args) {
        
        // Read the number of nodes
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Initialize the union-find structure
        init();

        // Read the coordinates of each node and assign an ID
        Node[] node = new Node[maxn];
        for (int i = 1; i <= n; i++) {
            node[i] = new Node();
            node[i].x = sc.nextInt();
            node[i].y = sc.nextInt();
            node[i].id = i; // Assign ID to the node
        }

        // Sort nodes based on their x-coordinate
        Arrays.sort(node, 1, n + 1, new cmp1());

        int cnt = 0; // Counter for edges
        // Create edges based on x-coordinates
        Edge[] e = new Edge[maxn << 1];
        for (int i = 2; i <= n; i++)
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        
        // Sort nodes based on their y-coordinate
        Arrays.sort(node, 1, n + 1, new cmp2());
        // Create edges based on y-coordinates
        for (int i = 2; i <= n; i++)
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);

        // Sort edges based on their weight
        Arrays.sort(e, 0, cnt, new Comparator<Edge>() {
            public int compare(Edge a, Edge b) {
                return a.less(b) ? -1 : 1;
            }
        });

        long ans = 0; // Variable to store the total weight of the minimum spanning tree
        // Process each edge in sorted order
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            // If u and v are already connected, skip this edge
            if (findpar(u) == findpar(v)) continue;
            unite(u, v); // Union the two nodes
            ans += val; // Add the weight of this edge to the total
        }

        // Output the total weight of the minimum spanning tree
        System.out.println(ans);

        // End of the program
    }
}

