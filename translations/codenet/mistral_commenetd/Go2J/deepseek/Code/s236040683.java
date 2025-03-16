import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // out is a custom function for printing output.
    public static void out(Object... x) {
        for (Object obj : x) {
            System.out.println(obj);
        }
    }

    // Node is a custom data structure for representing a node in the graph.
    static class Node {
        List<Integer> to = new ArrayList<>();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes N and edges M from the input.
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create an array of size N to store the nodes.
        Node[] n = new Node[N];
        for (int i = 0; i < N; i++) {
            n[i] = new Node();
        }

        // Process each edge by adding it to the to list of the corresponding nodes.
        for (int i = 0; i < M; i++) {
            // Read the from and to nodes from the input.
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;

            // Add the edge to the to list of the from node.
            n[from].to.add(to);

            // Add the edge to the to list of the to node.
            n[to].to.add(from);
        }

        // Print the number of neighbors for each node.
        for (int i = 0; i < N; i++) {
            // Print the number of neighbors of the current node.
            out(n[i].to.size());
        }
    }
}
