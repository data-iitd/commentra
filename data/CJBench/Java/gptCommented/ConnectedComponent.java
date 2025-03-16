import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Generic Graph class that can hold nodes of any type that is comparable
class Graph<E extends Comparable<E>> {
    // Inner class representing a Node in the graph
    class Node {
        E name; // Name of the node
        Node(E name) {
            this.name = name; // Constructor to initialize the node's name
        }
    }

    // Inner class representing an Edge in the graph
    class Edge {
        Node startNode; // Starting node of the edge
        Node endNode;   // Ending node of the edge
        Edge(Node startNode, Node endNode) {
            this.startNode = startNode; // Constructor to initialize the edge's start node
            this.endNode = endNode;     // Constructor to initialize the edge's end node
        }
    }

    // Lists to hold edges and nodes of the graph
    ArrayList<Edge> edgeList;
    ArrayList<Node> nodeList;

    // Constructor to initialize the graph
    Graph() {
        edgeList = new ArrayList<>(); // Initialize the edge list
        nodeList = new ArrayList<>(); // Initialize the node list
    }

    // Method to add an edge between two nodes in the graph
    public void addEdge(E startNode, E endNode) {
        Node start = null; // Variable to hold the starting node
        Node end = null;   // Variable to hold the ending node

        // Search for existing nodes in the node list
        for (Node node : nodeList) {
            if (startNode.compareTo(node.name) == 0) {
                start = node; // Found the starting node
            } else if (endNode.compareTo(node.name) == 0) {
                end = node; // Found the ending node
            }
        }

        // If the starting node does not exist, create and add it to the node list
        if (start == null) {
            start = new Node(startNode);
            nodeList.add(start);
        }
        // If the ending node does not exist, create and add it to the node list
        if (end == null) {
            end = new Node(endNode);
            nodeList.add(end);
        }

        // Add a new edge connecting the start and end nodes
        edgeList.add(new Edge(start, end));
    }

    // Method to count the number of distinct graphs in the graph
    public int countGraphs() {
        int count = 0; // Counter for distinct graphs
        Set<Node> markedNodes = new HashSet<>(); // Set to keep track of visited nodes

        // Iterate through all nodes in the node list
        for (Node n : nodeList) {
            // If the node has not been visited, perform DFS
            if (markedNodes.add(n)) {
                markedNodes.addAll(depthFirstSearch(n, new ArrayList<>())); // Mark all reachable nodes
                count++; // Increment the graph count
            }
        }
        return count; // Return the total count of distinct graphs
    }

    // Private method to perform depth-first search (DFS) on the graph
    private ArrayList<Node> depthFirstSearch(Node n, ArrayList<Node> visited) {
        visited.add(n); // Mark the current node as visited

        // Explore all edges starting from the current node
        for (Edge e : edgeList) {
            // If the edge starts from the current node and the end node is not visited
            if (e.startNode.equals(n) && !visited.contains(e.endNode)) {
                depthFirstSearch(e.endNode, visited); // Recursively visit the end node
            }
        }
        return visited; // Return the list of visited nodes
    }
}

// Main class to execute the program
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input

        // Read the number of edges for character graph
        int charEdges = scanner.nextInt();
        Graph<Character> graphChars = new Graph<>(); // Create a graph for characters

        // Read edges for the character graph
        for (int i = 0; i < charEdges; i++) {
            char start = scanner.next().charAt(0); // Read starting character
            char end = scanner.next().charAt(0);   // Read ending character
            graphChars.addEdge(start, end); // Add the edge to the graph
        }

        // Read the number of edges for integer graph
        int intEdges = scanner.nextInt();
        Graph<Integer> graphInts = new Graph<>(); // Create a graph for integers

        // Read edges for the integer graph
        for (int i = 0; i < intEdges; i++) {
            int start = scanner.nextInt(); // Read starting integer
            int end = scanner.nextInt();   // Read ending integer
            graphInts.addEdge(start, end); // Add the edge to the graph
        }

        // Output the number of distinct character graphs
        System.out.println("Amount of different char-graphs: " + graphChars.countGraphs());
        // Output the number of distinct integer graphs
        System.out.println("Amount of different int-graphs: " + graphInts.countGraphs());
    }
}
