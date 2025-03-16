
import java.util.ArrayList;
import java.util.Scanner;
public class LeftistHeap {
    private static final class Node {
        private final int element;
        private int npl;
        private Node left;
        private Node right;
        private Node(int element) {
            this.element = element;
            left = null;
            right = null;
            npl = 0;
        }
    }
    private Node root;
    public LeftistHeap() {
        root = null;
    }
    public boolean isEmpty() {
        return root == null;
    }
    public void clear() {
        root = null;
    }
    public void merge(LeftistHeap h1) {
        root = merge(root, h1.root);
        h1.root = null;
    }
    public Node merge(Node a, Node b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.element > b.element) {
            Node temp = a;
            a = b;
            b = temp;
        }
        a.right = merge(a.right, b);
        if (a.left == null) {
            a.left = a.right;
            a.right = null;
        } else if (a.left.npl < a.right.npl) {
            Node temp = a.left;
            a.left = a.right;
            a.right = temp;
        }
        a.npl = a.right == null ? 0 : a.right.npl + 1;
        return a;
    }
    public void insert(int a) {
        root = merge(new Node(a), root);
    }
    public int extractMin() {
        if (isEmpty()) return -1;
        int min = root.element;
        root = merge(root.left, root.right);
        return min;
    }
    public ArrayList<Integer> inOrder() {
        ArrayList<Integer> lst = new ArrayList<>();
        inOrderAux(root, lst);
        return lst;
    }
    private void inOrderAux(Node n, ArrayList<Integer> lst) {
        if (n == null) return;
        inOrderAux(n.left, lst);
        lst.add(n.element);
        inOrderAux(n.right, lst);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LeftistHeap heap = new LeftistHeap();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) break;
            String[] parts = command.split(" ");
            String operation = parts[0];
            try {
                switch (operation) {
                    case "insert": 
                        int value = Integer.parseInt(parts[1]);
                        heap.insert(value);
                        System.out.println("Inserted: " + value);
                        break;
                    case "extractMin": 
                        int min = heap.extractMin();
                        System.out.println(min == -1 ? "Heap is empty" : "Extracted Min: " + min);
                        break;
                    case "inOrder": 
                        ArrayList<Integer> inOrderList = heap.inOrder();
                        System.out.println("In-Order: " + inOrderList);
                        break;
                    case "clear": 
                        heap.clear();
                        System.out.println("Heap cleared");
                        break;
                    case "isEmpty": 
                        System.out.println("Is Empty: " + heap.isEmpty());
                        break;
                    default:
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
