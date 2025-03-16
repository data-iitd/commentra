import java.util.Scanner;

class STNode {
    STNode stParent;
    STNode stLeft;
    STNode stRight;
    int s4Key;

    public STNode(int key) {
        this.s4Key = key;
        this.stParent = null;
        this.stLeft = null;
        this.stRight = null;
    }
}

public class BinaryTree {
    private STNode stRoot;

    public void insert(int key) {
        STNode newNode = new STNode(key);
        STNode parentNode = null;
        STNode indexNode = stRoot;

        while (indexNode != null) {
            parentNode = indexNode;
            if (newNode.s4Key < indexNode.s4Key) {
                indexNode = indexNode.stLeft;
            } else {
                indexNode = indexNode.stRight;
            }
        }
        newNode.stParent = parentNode;

        if (parentNode == null) {
            stRoot = newNode;
        } else if (key < parentNode.s4Key) {
            parentNode.stLeft = newNode;
        } else {
            parentNode.stRight = newNode;
        }
    }

    public void print() {
        printInOrder(stRoot);
        System.out.println();
        printPreOrder(stRoot);
        System.out.println();
    }

    private void printPreOrder(STNode node) {
        if (node == null) {
            return;
        }
        System.out.print(" " + node.s4Key);
        printPreOrder(node.stLeft);
        printPreOrder(node.stRight);
    }

    private void printInOrder(STNode node) {
        if (node == null) {
            return;
        }
        printInOrder(node.stLeft);
        System.out.print(" " + node.s4Key);
        printInOrder(node.stRight);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree tree = new BinaryTree();

        // Number of commands
        int numCommands = scanner.nextInt();

        // Execute commands
        for (int i = 0; i < numCommands; i++) {
            String command = scanner.next();
            if (command.equals("insert")) {
                int insertKey = scanner.nextInt();
                tree.insert(insertKey);
            } else {
                tree.print();
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
