
import java.util.Scanner; // Importing Scanner class for reading input from the console
import javax.swing.tree.TreeNode; // Importing TreeNode interface for creating tree nodes

public class Main<E> { // Defining a generic class named Main with type parameter E
    private E data; // Declaring a private instance variable named data of type E
    private Main<E> leftNode; // Declaring a private instance variable named leftNode of type Main<E>
    private Main<E> rightNode; // Declaring a private instance variable named rightNode of type Main<E>

    public Main(E data) { // Constructor for initializing a new node with given data
        this.data = data;
    }

    public E getData() { // Method for getting the data of the current node
        return data;
    }

    public void setLeftNode(Main<E> leftNode) { // Method for setting the left child node
        this.leftNode = leftNode;
    }

    public void setRightNode(Main<E> rightNode) { // Method for setting the right child node
        this.rightNode = rightNode;
    }

    public Main<E> getLeftNode() { // Method for getting the left child node
        return leftNode;
    }

    public Main<E> getRightNode() { // Method for getting the right child node
        return rightNode;
    }

    public boolean isLeafNode() { // Method for checking if the current node is a leaf node (has no children)
        return leftNode == null && rightNode == null;
    }

    public static void main(String[] args) { // Main method for reading input and performing tree construction
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for reading input from the console
        int n = scanner.nextInt(); // Reading the number of nodes in the tree from the console
        Main<Integer>[] nodes = new Main[n + 1]; // Creating an array of size n+1 to store the tree nodes

        for (int i = 1; i <= n; i++) { // Loop for creating new nodes and initializing them with their data
            nodes[i] = new Main<>(i);
        }

        for (int i = 0; i < n - 1; i++) { // Loop for reading the parent-child relationships and connecting the nodes
            int parent = scanner.nextInt(); // Reading the parent node index from the console
            int child = scanner.nextInt(); // Reading the child node index from the console
            String direction = scanner.next(); // Reading the direction of the relationship (L for left or R for right)

            if (direction.equals("L")) { // If the relationship is left, set the left child of the parent node
                nodes[parent].setLeftNode(nodes[child]);
            } else if (direction.equals("R")) { // If the relationship is right, set the right child of the parent node
                nodes[parent].setRightNode(nodes[child]);
            }
        }

        preOrderTraversal(nodes[1]); // Performing pre-order traversal of the tree starting from the root node
        scanner.close(); // Closing the Scanner object
    }

    private static void preOrderTraversal(Main<Integer> root) { // Recursive method for performing pre-order traversal of the tree
        if (root == null) { // Base case: if the root is null, return
            return;
        }

        System.out.print(root.getData() + " "); // Printing the data of the current node
        preOrderTraversal(root.getLeftNode()); // Recursively traversing the left subtree
        preOrderTraversal(root.getRightNode()); // Recursively traversing the right subtree
    }
}

