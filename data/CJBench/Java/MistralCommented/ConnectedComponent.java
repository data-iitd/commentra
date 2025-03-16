
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

// Define a generic graph class with inner classes Node and Edge
class Graph<E extends Comparable<E>> {

    // Initialize inner classes edgeList and nodeList
    ArrayList<Edge> edgeList;
    ArrayList<Node> nodeList;
    Graph() {
        edgeList = new ArrayList<>();
        nodeList = new ArrayList<>();
    }

    // Add an edge between two nodes
    public void addEdge(E startNode, E endNode) {
        Node start = null;
        Node end = null;

        // Iterate through nodeList to find start and end nodes
        for (Node node : nodeList) {
            if (startNode.compareTo(node.name) == 0) {
                start = node;
            } else if (endNode.compareTo(node.name) == 0) {
                end = node;
            }
        }

        // If start node is not found, create a new Node and add it to nodeList
        if (start == null) {
            start = new Node(startNode);
            nodeList.add(start);
        }

        // If end node is not found, create a new Node and add it to nodeList
        if (end == null) {
            end = new Node(endNode);
            nodeList.add(end);
        }

        // Add the edge to edgeList
        edgeList.add(new Edge(start, end));
    }

    // Count the number of connected components in the graph
    public int countGraphs() {
        int count = 0;
        Set<Node> markedNodes = new HashSet<>();

        // Iterate through nodeList and mark each unvisited node and its connected components
        for (Node n : nodeList) {
            if (markedNodes.add(n)) {
                // Recursively mark all nodes reachable from n
                markedNodes.addAll(depthFirstSearch(n));
                count++;
            }
        }
        return count;
    }

    // Perform depth-first search from a given node and mark all reachable nodes
    private List<Node> depthFirstSearch(Node n, List<Node> visited) {
        visited.add(n);

        // Iterate through edgeList to mark all reachable nodes
        for (Edge e : edgeList) {
            if (e.startNode.equals(n) && !visited.contains(e.endNode)) {
                // Recursively call depthFirstSearch for the reachable node
                List<Node> reachableNodes = depthFirstSearch(e.endNode, new ArrayList<>());
                visited.addAll(reachableNodes);
            }
        }

        // Return the list of visited nodes
        return visited;
    }
}

// Main class to read input and print output
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of character edges
        int charEdges = scanner.nextInt();

        // Initialize a Graph object for characters
        Graph<Character> graphChars = new Graph<>();

        // Read character edges and add them to the graph
        for (int i = 0; i < charEdges; i++) {
            char start = scanner.next().charAt(0);
            char end = scanner.next().charAt(0);
            graphChars.addEdge(start, end);
        }

        // Read the number of integer edges
        int intEdges = scanner.nextInt();

        // Initialize a Graph object for integers
        Graph<Integer> graphInts = new Graph<>();

        // Read integer edges and add them to the graph
        for (int i = 0; i < intEdges; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            graphInts.addEdge(start, end);
        }

        // Print the number of different connected components in the character and integer graphs
        System.out.println("Amount of different char-graphs: " + graphChars.countGraphs());
        System.out.println("Amount of different int-graphs: " + graphInts.countGraphs());

        // Close the scanner
        scanner.close();
    }
}