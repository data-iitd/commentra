
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        new Main();
    }

    class Node {
        int x, y, id; // x and y coordinates, id of each node
    }

    class Edge {
        int u, v, val; // u and v are the ids of the nodes connected by the edge, the value of the edge
    }

    Node[] node; // array of nodes
    Edge[] e; // array of edges
    int n; // number of nodes in the graph
    int[] par; // parent array to keep track of the parent of each node in the disjoint set data structure

    // Comparator function for sorting nodes based on their x-coordinates
    public boolean cmp1(Node a, Node b) {
        return a.x < b.x;
    }

    // Comparator function for sorting nodes based on their y-coordinates
    public boolean cmp2(Node a, Node b) {
        return a.y < b.y;
    }

    // Initialization function for the disjoint set data structure
    public void init() {
        for (int i = 0; i <= n; i ++)
            par[i] = i; // each node initially belongs to its own set
    }

    // Function to find the representative of a set
    public int findpar(int x) {
        return par[x] = (par[x] == x? x : findpar(par[x])); // path compression is used to reduce the height of the tree
    }

    // Function to merge two sets
    public void unite(int x, int y) {
        x = findpar(x), y = findpar(y);
        if (x == y) return; // no need to merge if they already belong to the same set
        par[x] = y; // merge by making the root of set y as the parent of the root of set x
    }

    public Main() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); // read the number of nodes in the graph

        node = new Node[n + 1]; // create the array of nodes
        e = new Edge[n << 1]; // create the array of edges
        par = new int[n + 1]; // create the parent array

        init(); // initialize the disjoint set data structure

        // Read the coordinates of each node and assign an id to it
        for (int i = 1; i <= n; i ++) {
            node[i] = new Node();
            node[i].x = sc.nextInt();
            node[i].y = sc.nextInt();
            node[i].id = i; // id is just the index of the node in the node array
        }

        // Sort the nodes based on their x-coordinates
        Arrays.sort(node, 1, n + 1, this::cmp1);

        int cnt = 0; // initialize the counter for the number of edges
        // Create edges between adjacent nodes based on their x-coordinates
        for (int i = 2; i <= n; i ++) {
            e[cnt++] = new Edge();
            e[cnt - 1].u = node[i - 1].id;
            e[cnt - 1].v = node[i].id;
            e[cnt - 1].val = node[i].x - node[i - 1].x;
        }

        // Sort the nodes based on their y-coordinates
        Arrays.sort(node, 1, n + 1, this::cmp2);
        // Create edges between adjacent nodes based on their y-coordinates
        for (int i = 2; i <= n; i ++) {
            e[cnt++] = new Edge();
            e[cnt - 1].u = node[i - 1].id;
            e[cnt - 1].v = node[i].id;
            e[cnt - 1].val = node[i].y - node[i - 1].y;
        }

        // Sort the edges based on their values
        Arrays.sort(e, 0, cnt, (a, b) -> a.val - b.val);

        long ans = 0; // initialize the answer to 0
        // Process each edge in the sorted order
        for (int i = 0; i < cnt; i ++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            // Skip if the nodes are already in the same set
            if (findpar(u) == findpar(v)) continue;
            // Merge the sets of the nodes and add the value of the edge to the answer
            unite(u, v);
            ans += val;
        }

        System.out.println(ans); // print the final answer
    }
}

