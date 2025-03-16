
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Class representing a graph with cycles detection functionality using Depth First Search algorithm.
 */
class Cycle {
    private final int nodes;
    private int[][] adjacencyMatrix;
    private boolean[] visited;
    ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();

    /**
     * Constructor for Cycle class.
     *
     * @param nodes      number of nodes in the graph
     * @param edges      number of edges in the graph
     * @param edgesInput array of edges as input
     */
    Cycle(int nodes, int edges, int[][] edgesInput) {
        this.nodes = nodes;
        adjacencyMatrix = new int[nodes][nodes];
        visited = new boolean[nodes];
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }
        for (int[] edge : edgesInput) {
            int start = edge[0];
            int end = edge[1];
            adjacencyMatrix[start][end] = 1;
            adjacencyMatrix[end][start] = 1; // Add comment: Set bidirectional edge
        }
    }

    /**
     * Starts the cycles detection process.
     */
    public void start() {
        for (int i = 0; i < nodes; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            dfs(i, i, temp);
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
                adjacencyMatrix[j][i] = 0; // Add comment: Reset edge to zero
            }
        }
    }

    /**
     * Depth First Search algorithm implementation for cycles detection.
     *
     * @param start      the starting node
     * @param curr       the current node
     * @param temp       the list to store the nodes in the cycle
     */
    private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
        temp.add(curr);
        visited[curr] = true; // Add comment: Mark the current node as visited
        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[curr][i] == 1) {
                if (i == start) { // Add comment: Check if the current node is the starting node
                    cycles.add(new ArrayList<>(temp));
                    return; // Add comment: Add the cycle to the list and exit the method
                } else {
                    if (!visited[i]) { // Add comment: Check if the neighboring node is not visited yet
                        dfs(start, i, temp); // Add comment: Recursively call the dfs method for the neighboring node
                    }
                }
            }
        }
        if (temp.size() > 0) { // Add comment: If there are nodes in the temp list, remove the last one
            temp.remove(temp.size() - 1);
        }
        visited[curr] = false; // Add comment: Mark the current node as not visited
    }

    /**
     * Prints all the cycles found in the graph.
     */
    public void printAll() {
        if (cycles.isEmpty()) { // Add comment: Check if there are any cycles found
            System.out.println("No cycles found.");
            return;
        }
        for (ArrayList<Integer> cycle : cycles) { // Add comment: Iterate through each cycle found
            System.out.print("Cycle: ");
            for (int i = 0; i < cycle.size(); i++) { // Add comment: Print each node in the cycle
                System.out.print(cycle.get(i) + " -> ");
            }
            System.out.println(cycle.get(0)); // Add comment: Print the starting node of the cycle
            System.out.println(); // Add comment: Print a new line after each cycle
        }
    }
}

public final class Main {
    private Main() {
    }

    /**
     * Main method to read input and start the cycles detection process.
     *
     * @param args command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Add comment: Initialize a Scanner object to read input
        int nodes = scanner.nextInt(); // Add comment: Read the number of nodes from the input
        int edges = scanner.nextInt(); // Add comment: Read the number of edges from the input
        int[][] edgesInput = new int[edges][2]; // Add comment: Initialize an array to store edges as input
        for (int i = 0; i < edges; i++) { // Add comment: Read edges from the input and store them in the edgesInput array
            edgesInput[i][0] = scanner.nextInt();
            edgesInput[i][1] = scanner.nextInt();
        }
        Cycle cycleFinder = new Cycle(nodes, edges, edgesInput); // Add comment: Initialize a Cycle object with the given input
        cycleFinder.start(); // Add comment: Start the cycles detection process
        cycleFinder.printAll(); // Add comment: Print all the cycles found in the graph