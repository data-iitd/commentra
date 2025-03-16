
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
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
