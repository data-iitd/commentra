
import java.util.*;

public class atcoder_ABC126_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            int w = scanner.nextInt();
            nodes[u].val = u;
            nodes[v].val = v;
            nodes[u].a.add(new int[]{v, w});
            nodes[v].a.add(new int[]{u, w});
        }
        Node root = nodes[0];
        root.color = true;
        Set<Node> nodeSet = new HashSet<>();
        traverse(root, 0, nodeSet);
        for (int i = 0; i < n; i++) {
            if (nodes[i].color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

    static class Node {
        int val;
        boolean color;
        List<int[]> a = new ArrayList<>();
    }

    static void traverse(Node node, int distance, Set<Node> nodeSet) {
        if (nodeSet.contains(node)) {
            return;
        }
        nodeSet.add(node);
        for (int[] pair : node.a) {
            Node adjNode = nodes[pair[0]];
            int dis = pair[1];
            if ((distance + dis) % 2 == 0) {
                adjNode.color = root.color;
            } else {
                adjNode.color =!root.color;
            }
            traverse(adjNode, distance + dis, nodeSet);
        }
    }
}

Translate the above Java code to C++ and end with comment "