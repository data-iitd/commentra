
import java.util.*;
import java.util.HashMap;
public class BoundaryTraversal {
    static class Node {
        int data;
        Node left;
        Node right;
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    public static List<Integer> boundaryTraversal(Node root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        if (!isLeaf(root)) {
            result.add(root.data);
        }
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);
        return result;
    }
    private static void addLeftBoundary(Node node, List<Integer> result) {
        Node cur = node.left;
        while (cur != null) {
            if (!isLeaf(cur)) {
                result.add(cur.data);
            }
            cur = (cur.left != null) ? cur.left : cur.right;
        }
    }
    private static void addLeaves(Node node, List<Integer> result) {
        if (node == null) {
            return;
        }
        if (isLeaf(node)) {
            result.add(node.data);
        } else {
            addLeaves(node.left, result);
            addLeaves(node.right, result);
        }
    }
    private static void addRightBoundary(Node node, List<Integer> result) {
        Node cur = node.right;
        Stack<Integer> temp = new Stack<>();
        while (cur != null) {
            if (!isLeaf(cur)) {
                temp.push(cur.data);
            }
            cur = (cur.right != null) ? cur.right : cur.left;
        }
        while (!temp.isEmpty()) {
            result.add(temp.pop());
        }
    }
    private static boolean isLeaf(Node node) {
        return node.left == null && node.right == null;
    }
    public static Node buildTree(Scanner scanner) {
        int n = scanner.nextInt();
        Map<Integer, Node> map = new HashMap<>();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int parent = scanner.nextInt();
            String direction = scanner.next();
            int child = scanner.nextInt();
            Node parentNode = map.getOrDefault(parent, new Node(parent));
            Node childNode = new Node(child);
            if (direction.equals("L")) {
                parentNode.left = childNode;
            } else if (direction.equals("R")) {
                parentNode.right = childNode;
            }
            map.put(parent, parentNode);
            map.put(child, childNode);
            if (root == null) {
                root = parentNode;
            }
        }
        return root;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of nodes and edges:");
        Node root = buildTree(scanner);
        System.out.println("Boundary traversal:");
        List<Integer> result = boundaryTraversal(root);
        for (int value : result) {
            System.out.print(value + " ");
        }
        System.out.println();
        scanner.close();
    }
}
