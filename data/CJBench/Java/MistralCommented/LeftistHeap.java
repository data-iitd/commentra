
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    // Initialize an empty heap
    private static final class Node {
        private final int element;
        private int npl; // number of nodes in the left subtree
        private Node left;
        private Node right;
        private Node(int element) {
            this.element = element;
            left = null;
            right = null;
            npl = 0;
        }
    }

    private Node root; // root of the heap

    // Constructor
    public Main() {
        root = null;
    }

    // Check if the heap is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Clear the heap
    public void clear() {
        root = null;
    }

    // Merge two heaps
    public void merge(Main h1) {
        root = merge(root, h1.root);
        h1.root = null;
    }

    // Merge two nodes recursively
    private Node merge(Node a, Node b) {
        if (a == null) return b; // if a is null, return b
        if (b == null) return a; // if b is null, return a

        if (a.element > b.element) { // if a's value is greater than b's value
            Node temp = a; // swap a and b
            a = b;
            b = temp;
        }

        a.right = merge(a.right, b); // merge their right subtrees

        if (a.left == null) { // if a has no left child
            a.left = a.right; // make a's left child a's right child
            a.right = null; // a no longer has a right child
        } else if (a.left.npl < a.right.npl) { // if the number of nodes in a's left subtree is less than the number of nodes in a's right subtree
            Node temp = a.left; // swap a's left and right children
            a.left = a.right;
            a.right = temp;
        }

        a.npl = a.right == null ? 0 : a.right.npl + 1; // update the number of nodes in a's left subtree

        return a; // return the merged node
    }

    // Insert a value into the heap
    public void insert(int a) {
        root = merge(new Node(a), root); // merge the new node with the root
    }

    // Extract and return the minimum value from the heap
    public int extractMin() {
        if (isEmpty()) return -1; // if the heap is empty, return -1

        int min = root.element; // save the minimum value
        root = merge(root.left, root.right); // merge the left and right subtrees to get the new root

        return min; // return the minimum value
    }

    // Traverse the heap in-order and return a list of the values
    public ArrayList<Integer> inOrder() {
        ArrayList<Integer> lst = new ArrayList<>(); // initialize an empty list
        inOrderAux(root, lst); // traverse the heap in-order and add the values to the list
        return lst;
    }

    // Traverse the heap in-order recursively and add the values to the list
    private void inOrderAux(Node n, ArrayList<Integer> lst) {
        if (n == null) return; // if n is null, return

        inOrderAux(n.left, lst); // traverse the left subtree
        lst.add(n.element); // add the value of n to the list
        inOrderAux(n.right, lst); // traverse the right subtree
    }

    // Main method to read commands from the user and execute them
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // initialize a scanner to read input from the user

        Main heap = new Main(); // initialize an empty heap

        while (scanner.hasNextLine()) { // read commands from the user until there is no more input
            String command = scanner.nextLine().trim(); // read the command

            if (command.isEmpty()) break; // if the command is empty, break out of the loop

            String[] parts = command.split(" "); // split the command into parts
            String operation = parts[0]; // get the operation

            try {
                switch (operation) { // switch on the operation
                    case "insert": // if the operation is "insert", insert the value
                        int value = Integer.parseInt(parts[1]);
                        heap.insert(value);
                        System.out.println("Inserted: " + value);
                        break;
                    case "extractMin": // if the operation is "extractMin", extract and print the minimum value
                        int min = heap.extractMin();
                        System.out.println(min == -1 ? "Heap is empty" : "Extracted Min: " + min);
                        break;
                    case "inOrder": // if the operation is "inOrder", print the values in-order
                        ArrayList<Integer> inOrderList = heap.inOrder();
                        System.out.println("In-Order: " + inOrderList);
                        break;
                    case "clear": // if the operation is "clear", clear the heap
                        heap.clear();
                        System.out.println("Heap cleared");
                        break;
                    case "isEmpty": // if the operation is "isEmpty", print whether the heap is empty or not
                        System.out.println("Is Empty: " + heap.isEmpty());
                        break;
                    default: // if the operation is not recognized, print an error message
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) { // catch any exceptions and print an error message
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close(); // close the scanner
    }
}