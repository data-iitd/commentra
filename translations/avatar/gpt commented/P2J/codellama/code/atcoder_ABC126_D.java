
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            int w = in.nextInt();
            Node node1 = nodes[u - 1];
            Node node2 = nodes[v - 1];
            node1.val = u;
            node2.val = v;
            node1.a.add(new int[] { node2.val, w });
            node2.a.add(new int[] { node1.val, w });
        }
        Node root = nodes[0];
        root.color = true;
        Set<Integer> nodeSet = new HashSet<>();
        traverse(root, 0);
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

    public static void traverse(Node node, int distance) {
        if (nodeSet.contains(node.val)) {
            return;
        } else {
            nodeSet.add(node.val);
        }
        for (int[] pair : node.a) {
            Node adjNode = nodes[pair[0] - 1];
            int dis = pair[1];
            if ((distance + dis) % 2 == 0) {
                adjNode.color = root.color;
            } else {
                adjNode.color = !root.color;
            }
            traverse(adjNode, distance + dis);
        }
    }
}

class Node {
    int val;
    boolean color;
    List<int[]> a = new ArrayList<>();
}

