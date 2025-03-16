import java.util.*; // Importing necessary libraries

public class Main {
    @SuppressWarnings("unchecked") // Suppressing unchecked warnings
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        int numNode = sc.nextInt(); // Reading the number of nodes
        int numEdge = sc.nextInt(); // Reading the number of edges
        
        // Initializing adjacency lists for each node
        ArrayList<Integer>[] connect = new ArrayList[numNode];
        for (int i = 0; i < numNode; i++) {
            connect[i] = new ArrayList<>();
        }
        
        // Reading edges and populating the adjacency lists
        for (int i = 0; i < numEdge; i++) {
            int a = sc.nextInt() - 1; // Reading node a and converting to zero-based index
            int b = sc.nextInt() - 1; // Reading node b and converting to zero-based index
            connect[a].add(b); // Adding edge from a to b
            connect[b].add(a); // Adding edge from b to a
        }
        
        // Checking if the number of edges is odd
        if (numEdge % 2 != 0) {
            System.out.println(-1); // Printing -1 if the number of edges is odd
            return; // Returning from the main method
        }
        
        // Initializing arrays for DFS
        visited = new int[numNode];
        odd = new boolean[numNode];
        print = new StringBuilder();
        
        // Performing DFS starting from node 0
        dfs(0, -1);
        
        // Outputting the result
        System.out.println(print);
    }
    
    // Declaring static arrays to be used in the dfs method
    static ArrayList<Integer>[] connect;
    static int[] visited;
    static boolean[] odd;
    static StringBuilder print;
    
    // DFS method to traverse the graph
    static void dfs(int crt, int parent) {
        visited[crt] = 1; // Marking the current node as visited
        ArrayList<Integer> crtConnect = connect[crt]; // Getting the adjacency list of the current node
        
        // Traversing each child node of the current node
        for (int child : crtConnect) {
            if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
                continue;
            } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
                print.append((crt + 1) + " " + (child + 1) + "\n");
                odd[crt] = !odd[crt];
            } else { // Recursively calling dfs for unvisited child nodes
                dfs(child, crt);
                if (odd[child]) { // Updating the print and odd arrays based on the child's result
                    print.append((child + 1) + " " + (crt + 1) + "\n");
                    odd[child] = !odd[child];
                } else {
                    print.append((crt + 1) + " " + (child + 1) + "\n");
                    odd[crt] = !odd[crt];
                }
            }
        }
        visited[crt] = 2; // Marking the current node as fully processed
    }
}
