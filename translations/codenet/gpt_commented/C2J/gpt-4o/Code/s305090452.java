import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Define a class for a binary heap
class BinaryHeap {
    private Object[] array; // Array that holds the heap elements
    private int heapSize; // Current number of elements in the heap
    private int maxSize; // Maximum capacity of the heap
    private int valSize; // Size of each value in the heap
    private Comparator<Object> cmp; // Comparison function for heap elements

    // Constructor to create a new binary heap
    public BinaryHeap(int valSize, Comparator<Object> cmp) {
        this.valSize = valSize;
        this.cmp = cmp;
        this.maxSize = 1;
        this.heapSize = 0;
        this.array = new Object[maxSize + 1]; // 1-based index
    }

    // Function to get the current size of the heap
    public int getHeapSize() {
        return heapSize;
    }

    // Function to check if the heap is empty
    public boolean isEmpty() {
        return heapSize == 0;
    }

    // Function to push a new value into the heap
    public void push(Object val) {
        if (heapSize == maxSize) {
            maxSize = 2 * maxSize + 1; // Double the max size
            array = Arrays.copyOf(array, maxSize + 1); // Resize the array
        }
        heapSize++; // Increment the heap size
        array[heapSize] = val; // Copy the new value into the heap
        // Maintain the heap property by moving the new element up the heap
        int k = heapSize;
        while (k > 1) {
            int parent = k / 2; // Calculate the parent index
            if (cmp.compare(array[parent], array[k]) <= 0) {
                return; // If the heap property is satisfied, exit
            }
            swap(parent, k); // Swap with parent
            k = parent; // Move up to the parent
        }
    }

    // Function to pop the top value from the heap
    public Object pop() {
        if (isEmpty()) return null;
        Object res = array[1]; // Get the top value
        array[1] = array[heapSize]; // Move the last element to the top
        heapSize--; // Decrement the heap size
        // Maintain the heap property by moving the top element down the heap
        int k = 1;
        while (2 * k <= heapSize) {
            int next = 2 * k; // Left child
            if (next + 1 <= heapSize && cmp.compare(array[next], array[next + 1]) > 0) {
                next++; // Choose the smaller child
            }
            if (cmp.compare(array[k], array[next]) <= 0) return res; // If heap property is satisfied, exit
            swap(k, next); // Swap with the smaller child
            k = next; // Move down to the next level
        }
        return res;
    }

    // Function to swap two elements in the heap
    private void swap(int i, int j) {
        Object temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Function to get the top value of the heap without removing it
    public Object top() {
        return isEmpty() ? null : array[1];
    }
}

// Define a class for Union-Find (Disjoint Set Union)
class UnionFind {
    private int[] parent; // Array to hold the parent of each element
    private int size; // Size of the Union-Find structure

    // Constructor to create a new Union-Find structure
    public UnionFind(int size) {
        this.size = size;
        this.parent = new int[size];
        initUnionFind();
    }

    // Function to initialize the Union-Find structure
    private void initUnionFind() {
        Arrays.fill(parent, -1); // Set each element's parent to -1
    }

    // Function to find the root of an element with path compression
    public int root(int x) {
        if (parent[x] < 0) return x; // If x is a root, return it
        parent[x] = root(parent[x]); // Path compression
        return parent[x];
    }

    // Function to check if two elements are in the same set
    public boolean same(int x, int y) {
        return root(x) == root(y);
    }

    // Function to unite two sets containing elements x and y
    public void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return; // If they are already in the same set, do nothing
        // Union by size: attach the smaller tree under the larger tree
        if (parent[x] > parent[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[x] += parent[y]; // Update the size of the new root
        parent[y] = x; // Make x the parent of y
    }

    // Function to get the size of the set containing element x
    public int getSize(int x) {
        return -parent[root(x)];
    }
}

// Define a class for index-value pairs
class IndexVal {
    int index; // Index of the value
    int val; // Value

    IndexVal(int index, int val) {
        this.index = index;
        this.val = val;
    }
}

// Define a class for segment nodes
class SegmentNode {
    int index; // Index of the node
    long val; // Value of the node

    SegmentNode(int index, long val) {
        this.index = index;
        this.val = val;
    }
}

// Define a class for edges
class Edge {
    int a, b; // Endpoints of the edge
    long c; // Cost of the edge

    Edge(int a, int b, long c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

// Main class to run the algorithm
public class Main {
    public static void main(String[] args) {
        run();
    }

    // Main function to execute the algorithm
    private static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];

        // Read values and initialize index-value pairs
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            p[i] = new IndexVal(i, a[i]);
        }

        Arrays.sort(p, Comparator.comparingInt(iv -> iv.val)); // Sort index-value pairs by value
        SegmentNode ini = new SegmentNode(n, (long) (n + 2) * 1000000000 + 1); // Initialize segment node
        BinaryHeap h = new BinaryHeap(Edge.class.getDeclaredFields().length * Integer.BYTES, Comparator.comparingLong(e -> ((Edge) e).c)); // Create a new binary heap for edges

        // Process each index-value pair
        for (int i = 0; i < n; i++) {
            int v = p[i].index; // Get the original index
            if (v > 0) {
                // Find the minimum in the left segment tree
                // Push edge to heap
                h.push(new Edge(v, v - 1, p[i].val + ini.val - (long) (n - 1 - v) * d));
            }
            if (v + 1 < n) {
                // Find the minimum in the right segment tree
                // Push edge to heap
                h.push(new Edge(v, v + 1, p[i].val + ini.val - (long) v * d));
            }
        }

        long sum = 0; // Initialize sum of costs
        UnionFind u = new UnionFind(n); // Create a new Union-Find structure

        // Process edges in the heap to find the minimum spanning tree
        while (u.getSize(0) < n) {
            Edge e = (Edge) h.pop(); // Pop the minimum edge from the heap
            if (u.same(e.a, e.b)) continue; // If they are already connected, skip
            u.unite(e.a, e.b); // Union the sets
            sum += e.c; // Add the cost of the edge to the sum
        }
        System.out.println(sum); // Print the total cost
    }
}
// <END-OF-CODE>
