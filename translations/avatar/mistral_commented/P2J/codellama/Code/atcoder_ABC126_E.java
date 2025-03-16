// Import necessary libraries
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

// Define the main function
public class Main {
    // Define a custom input function
    public static String input() {
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    // Define the main function
    public static void main(String[] args) {
        // Read input values for N and M
        String[] NM = input().split(" ");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);

        // Initialize an empty list for edge
        int[][] edge = new int[N][];

        // Read edges and add them to the edge list
        for (int i = 0; i < M; i++) {
            String[] XYZ = input().split(" ");
            int X = Integer.parseInt(XYZ[0]) - 1;
            int Y = Integer.parseInt(XYZ[1]) - 1;
            int Z = Integer.parseInt(XYZ[2]) - 1;
            edge[X] = new int[Z];
            edge[Y] = new int[Z];
            edge[X][Y] = 1;
            edge[Y][X] = 1;
        }

        // Initialize a list of boolean values for used nodes
        boolean[] used = new boolean[N];

        // Initialize a variable for answer
        int ans = 0;

        // Iterate through all nodes
        for (int i = 0; i < N; i++) {
            // If the current node is not used
            if (!used[i]) {
                // Increment the answer
                ans++;
                // Initialize a queue for BFS traversal
                Queue<Integer> queue = new LinkedList<>();
                // Add the current node to the queue
                queue.add(i);
                // Traverse through the graph using BFS
                while (!queue.isEmpty()) {
                    // Get the next node from the queue
                    int node = queue.poll();
                    // Mark the current node as used
                    used[node] = true;
                    // Traverse through the neighbors of the current node
                    for (int nextnode : edge[node]) {
                        // If the neighbor is not used
                        if (!used[nextnode]) {
                            // Add the neighbor to the queue
                            queue.add(nextnode);
                        }
                    }
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

// End of code
