
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
class BinaryTree {
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}
public class VerticalOrderTraversal {
    public static ArrayList<Integer> verticalTraversal(BinaryTree.Node root) {
        if (root == null) {
            return new ArrayList<>();
        }
        Queue<BinaryTree.Node> queue = new LinkedList<>();
        Queue<Integer> index = new LinkedList<>();
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();
        int max = 0, min = 0;
        queue.offer(root);
        index.offer(0);
        while (!queue.isEmpty()) {
            BinaryTree.Node node = queue.poll();
            int idx = index.poll();
            map.putIfAbsent(idx, new ArrayList<>());
            map.get(idx).add(node.data);
            max = Math.max(max, idx);
            min = Math.min(min, idx);
            if (node.left != null) {
                queue.offer(node.left);
                index.offer(idx - 1);
            }
            if (node.right != null) {
                queue.offer(node.right);
                index.offer(idx + 1);
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = min; i <= max; i++) {
            result.addAll(map.get(i));
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        BinaryTree.Node[] nodes = new BinaryTree.Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new BinaryTree.Node(i);
        }
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            String direction = scanner.next();
            if (direction.equals("L")) {
                nodes[parent].left = nodes[child];
            } else if (direction.equals("R")) {
                nodes[parent].right = nodes[child];
            }
        }
        ArrayList<Integer> result = verticalTraversal(nodes[1]);
        for (int value : result) {
            System.out.print(value + " ");
        }
        scanner.close();
    }
}
