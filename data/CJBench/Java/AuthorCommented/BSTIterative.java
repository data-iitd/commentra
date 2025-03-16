import java.util.Scanner;

/**
 * BSTIterative implements a Binary Search Tree using an iterative approach.
 * Supports operations such as add, remove, find, and display.
 */
public class BSTIterative {

    private Node root;

    /**
     * Node class represents each node in the BST.
     */
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    /**
     * Default constructor initializes an empty BST.
     */
    public BSTIterative() {
        root = null;
    }

    /**
     * Adds a value to the BST.
     *
     * @param data the value to be added
     */
    public void add(int data) {
        Node parent = null;
        Node temp = this.root;
        int direction = -1;

        while (temp != null) {
            if (data < temp.data) {
                parent = temp;
                temp = temp.left;
                direction = 0;
            } else if (data > temp.data) {
                parent = temp;
                temp = temp.right;
                direction = 1;
            } else {
                System.out.println(data + " is already present in BST.");
                return;
            }
        }

        Node newNode = new Node(data);
        if (parent == null) {
            this.root = newNode; // Insert as root if BST is empty
        } else if (direction == 0) {
            parent.left = newNode; // Insert as left child
        } else {
            parent.right = newNode; // Insert as right child
        }
    }

    /**
     * Removes a value from the BST.
     *
     * @param data the value to remove
     */
    public void remove(int data) {
        Node parent = null;
        Node temp = this.root;
        int direction = -1;

        while (temp != null) {
            if (temp.data == data) {
                break;
            } else if (data < temp.data) {
                parent = temp;
                temp = temp.left;
                direction = 0;
            } else {
                parent = temp;
                temp = temp.right;
                direction = 1;
            }
        }

        if (temp != null) {
            Node replacement = null;

            if (temp.left == null && temp.right == null) {
                replacement = null; // Case 1: No children
            } else if (temp.left == null) {
                replacement = temp.right; // Case 2: Right child only
            } else if (temp.right == null) {
                replacement = temp.left; // Case 3: Left child only
            } else {
                // Case 4: Two children
                Node successorParent = temp;
                Node successor = temp.right;

                while (successor.left != null) {
                    successorParent = successor;
                    successor = successor.left;
                }

                temp.data = successor.data; // Replace with successor
                if (successorParent != temp) {
                    successorParent.left = successor.right;
                } else {
                    successorParent.right = successor.right;
                }
                return;
            }

            if (parent == null) {
                this.root = replacement; // Replace root
            } else if (direction == 0) {
                parent.left = replacement;
            } else {
                parent.right = replacement;
            }
        }
    }

    /**
     * Searches for a value in the BST.
     *
     * @param data the value to search for
     * @return true if the value exists, false otherwise
     */
    public boolean find(int data) {
        Node temp = this.root;

        while (temp != null) {
            if (data == temp.data) {
                System.out.println(data + " is present in the BST.");
                return true;
            } else if (data < temp.data) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }

        System.out.println(data + " not found.");
        return false;
    }

    /**
     * Displays the BST in in-order traversal.
     */
    public void display() {
        displayHelper(this.root);
        System.out.println();
    }

    private void displayHelper(Node node) {
        if (node != null) {
            displayHelper(node.left);
            System.out.print(node.data + " ");
            displayHelper(node.right);
        }
    }

    /**
     * Main method for interactive user input.
     */
    public static void main(String[] args) {
        BSTIterative bst = new BSTIterative();
        Scanner scanner = new Scanner(System.in);


        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();

            if (command.equalsIgnoreCase("exit")) {
                break;
            }

            String[] parts = command.split(" ");
            try {
                switch (parts[0]) {
                    case "add":
                        bst.add(Integer.parseInt(parts[1]));
                        System.out.println("Added: " + parts[1]);
                        break;

                    case "remove":
                        bst.remove(Integer.parseInt(parts[1]));
                        System.out.println("Removed: " + parts[1]);
                        break;

                    case "find":
                        bst.find(Integer.parseInt(parts[1]));
                        break;

                    case "display":
                        bst.display();
                        break;

                    default:
                        System.out.println("Unknown command: " + parts[0]);
                        break;
                }
            } catch (Exception e) {
                System.out.println("Error: Invalid command or input.");
            }
        }

        scanner.close();
    }
}
