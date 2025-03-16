import java.util.Scanner;
public class BSTIterative {
    private Node root;
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    public BSTIterative() {
        root = null;
    }
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
            this.root = newNode; 
        } else if (direction == 0) {
            parent.left = newNode; 
        } else {
            parent.right = newNode; 
        }
    }
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
                replacement = null; 
            } else if (temp.left == null) {
                replacement = temp.right; 
            } else if (temp.right == null) {
                replacement = temp.left; 
            } else {
                Node successorParent = temp;
                Node successor = temp.right;
                while (successor.left != null) {
                    successorParent = successor;
                    successor = successor.left;
                }
                temp.data = successor.data; 
                if (successorParent != temp) {
                    successorParent.left = successor.right;
                } else {
                    successorParent.right = successor.right;
                }
                return;
            }
            if (parent == null) {
                this.root = replacement; 
            } else if (direction == 0) {
                parent.left = replacement;
            } else {
                parent.right = replacement;
            }
        }
    }
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
    public static void main(String[] args) {
        BSTIterative bst = new BSTIterative();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter commands (add <value>, remove <value>, find <value>, display, exit):");
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
