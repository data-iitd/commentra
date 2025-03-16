
import java.util.Scanner;

class Node {
    int val;
    boolean color;
    Node[] a;

    public Node() {
        this.val = 0;
        this.color = false;
        this.a = new Node[0];
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].val = i + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            Node node1 = nodes[u - 1];
            Node node2 = nodes[v - 1];
            Node[] temp = new Node[node1.a.length + 1];
            for (int j = 0; j < node1.a.length; j++) {
                temp[j] = node1.a[j];
            }
            temp[temp.length - 1] = node2;
            node1.a = temp;
            temp = new Node[node2.a.length + 1];
            for (int j = 0; j < node2.a.length; j++) {
                temp[j] = node2.a[j];
            }
            temp[temp.length - 1] = node1;
            node2.a = temp;
        }
        Node root = nodes[0];
        root.color = true;
        Node[] nodeSet = new Node[n];
        for (int i = 0; i < n; i++) {
            nodeSet[i] = nodes[i];
        }
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }
}

