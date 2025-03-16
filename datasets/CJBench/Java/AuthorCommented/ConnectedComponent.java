
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * A class that counts the number of different connected components in a graph.
 */
class Graph<E extends Comparable<E>> {

    class Node {
        E name;

        Node(E name) {
            this.name = name;
        }
    }

    class Edge {
        Node startNode;
        Node endNode;

        Edge(Node startNode, Node endNode) {
            this.startNode = startNode;
            this.endNode = endNode;
        }
    }

    ArrayList<Edge> edgeList;
    ArrayList<Node> nodeList;

    Graph() {
        edgeList = new ArrayList<>();
        nodeList = new ArrayList<>();
    }

    /**
     * Adds a new Edge to the graph. If the nodes aren't yet in nodeList, they
     * will be added to it.
     *
     * @param startNode the starting Node from the edge
     * @param endNode the ending Node from the edge
     */
    public void addEdge(E startNode, E endNode) {
        Node start = null;
        Node end = null;
        for (Node node : nodeList) {
            if (startNode.compareTo(node.name) == 0) {
                start = node;
            } else if (endNode.compareTo(node.name) == 0) {
                end = node;
            }
        }
        if (start == null) {
            start = new Node(startNode);
            nodeList.add(start);
        }
        if (end == null) {
            end = new Node(endNode);
            nodeList.add(end);
        }
        edgeList.add(new Edge(start, end));
    }

    /**
     * Main method used for counting the connected components. Iterates through
     * the array of nodes to do a depth first search to get all nodes of the
     * graph from the actual node. These nodes are added to the array
     * markedNodes and will be ignored if they are chosen in the nodeList.
     *
     * @return returns the amount of unconnected graphs
     */
    public int countGraphs() {
        int count = 0;
        Set<Node> markedNodes = new HashSet<>();

        for (Node n : nodeList) {
            if (markedNodes.add(n)) {
                markedNodes.addAll(depthFirstSearch(n, new ArrayList<>()));
                count++;
            }
        }
        return count;
    }

    /**
     * Implementation of depth first search.
     *
     * @param n the actual visiting node
     * @param visited A list of already visited nodes in the depth first search
     * @return returns a set of visited nodes
     */
    private ArrayList<Node> depthFirstSearch(Node n, ArrayList<Node> visited) {
        visited.add(n);
        for (Edge e : edgeList) {
            if (e.startNode.equals(n) && !visited.contains(e.endNode)) {
                depthFirstSearch(e.endNode, visited);
            }
        }
        return visited;
    }
}

public class ConnectedComponent {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int charEdges = scanner.nextInt();
        Graph<Character> graphChars = new Graph<>();
        for (int i = 0; i < charEdges; i++) {
            char start = scanner.next().charAt(0);
            char end = scanner.next().charAt(0);
            graphChars.addEdge(start, end);
        }

        int intEdges = scanner.nextInt();
        Graph<Integer> graphInts = new Graph<>();
        for (int i = 0; i < intEdges; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            graphInts.addEdge(start, end);
        }

        System.out.println("Amount of different char-graphs: " + graphChars.countGraphs());
        System.out.println("Amount of different int-graphs: " + graphInts.countGraphs());
    }
}
