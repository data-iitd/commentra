import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Node {
        List<Integer> to = new ArrayList<>();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes (N) and the number of edges (M)
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize an array of Node with N elements
        Node[] nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node();
        }

        // Read M pairs of edges and populate the adjacency list for each node
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            nodes[from].to.add(to);
            nodes[to].to.add(from);
        }

        // Print the size of the adjacency list for each node
        for (int i = 0; i < N; i++) {
            System.out.println(nodes[i].to.size());
        }

        sc.close();
    }
}

// <END-OF-CODE>
