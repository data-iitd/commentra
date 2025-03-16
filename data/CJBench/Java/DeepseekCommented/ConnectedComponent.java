import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Graph class definition
class Graph<E extends Comparable<E>> {
    // Inner class Node represents a node in the graph
    class Node {
        E name;
        Node(E name) {
            this.name = name;
        }
    }
    // Inner class Edge represents an edge between two nodes
    class Edge {
        Node startNode;
        Node endNode;
        Edge(Node startNode, Node endNode) {
            this.startNode = startNode;
            this.endNode = endNode;
        }
    }
    // ArrayList to store edges
    ArrayList<Edge> edgeList;
    // ArrayList to store nodes
    ArrayList<Node> nodeList;
    // Constructor to initialize the graph
    Graph() {
        edgeList = new ArrayList<>();
        nodeList = new ArrayList<>();
    }
    // Method to add an edge between two nodes
    public void addEdge(E startNode, E endNode) {
        Node start = null;
        Node end = null;
        // Check if the start and end nodes already exist in the node list
        for (Node node : nodeList) {
            if (startNode.compareTo(node.name) == 0) {
                start = node;
            } else if (endNode.compareTo(node.name) == 0) {
                end = node;
            }
        }
        // If the start node does not exist, create a new node and add it to the list
        if (start == null) {
            start = new Node(startNode);
            nodeList.add(start);
        }
        // If the end node does not exist, create a new node and add it to the list
        if (end == null) {
            end = new Node(endNode);
            nodeList.add(end);
        }
        // Add the new edge to the edge list
        edgeList.add(new Edge(start, end));
    }
    // Method to count the number of connected components in the graph
    public int countGraphs() {
        int count = 0;
        // Set to keep track of marked nodes
        Set<Node> markedNodes = new HashSet<>();
        // Iterate through each node in the node list
        for (Node n : nodeList) {
            // If the node has not been marked, perform a depth-first search
            if (markedNodes.add(n)) {
                markedNodes.addAll(depthFirstSearch(n, new ArrayList<>()));
                count++;
            }
        }
        return count;
    }
    // Helper method for countGraphs to perform depth-first search
    private ArrayList<Node> depthFirstSearch(Node n, ArrayList<Node> visited) {
        visited.add(n);
        // Iterate through each edge in the edge list
        for (Edge e : edgeList) {
            if (e.startNode.equals(n) && !visited.contains(e.endNode)) {
                depthFirstSearch(e.endNode, visited);
            }
        }
        return visited;
    }
}

// Main class containing the main method
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of edges for characters
        int charEdges = scanner.nextInt();
        // Create a graph for characters
        Graph<Character> graphChars = new Graph<>();
        // Add edges for characters
        for (int i = 0; i < charEdges; i++) {
            char start = scanner.next().charAt(0);
            char end = scanner.next().charAt(0);
            graphChars.addEdge(start, end);
        }
        // Read the number of edges for integers
        int intEdges = scanner.nextInt();
        // Create a graph for integers
        Graph<Integer> graphInts = new Graph<>();
        // Add edges for integers
        for (int i = 0; i < intEdges; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            graphInts.addEdge(start, end);
        }
        // Print the number of different connected components for character graph
        System.out.println("Amount of different char-graphs: " + graphChars.countGraphs());
        // Print the number of different connected components for integer graph
        System.out.println("Amount of different int-graphs: " + graphInts.countGraphs());
    }
}
