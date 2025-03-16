import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            Node node1 = nodes[u - 1];
            Node node2 = nodes[v - 1];
            node1.val = u;
            node2.val = v;
            node1.a.add(new NodePair(node2, w));
            node2.a.add(new NodePair(node1, w));
        }
        Node root = nodes[0];
        root.color = true;
        Set<Node> nodeSet = new HashSet<>();
        traverse(root, 0, nodeSet);
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

    public static void traverse(Node node, int distance, Set<Node> nodeSet) {
        if (nodeSet.contains(node)) {
            return;
        } else {
            nodeSet.add(node);
        }
        for (NodePair pair : node.a) {
            Node adjNode = pair.node;
            int dis = pair.dis;
            if ((distance + dis) % 2 == 0) {
                adjNode.color = root.color;
            } else {
                adjNode.color =!root.color;
            }
            traverse(adjNode, distance + dis, nodeSet);
        }
    }
}

class Node {
    int val;
    boolean color;
    List<NodePair> a;

    public Node() {
        val = 0;
        color = false;
        a = new ArrayList<>();
    }
}

class NodePair {
    Node node;
    int dis;

    public NodePair(Node node, int dis) {
        this.node = node;
        this.dis = dis;
    }
}

