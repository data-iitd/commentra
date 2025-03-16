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

public class AVLTree {
    private STNode root;

    public void insert(int key) {
        root = insertRec(root, key);
    }

    private STNode insertRec(STNode node, int key) {
        if (node == null) {
            return new STNode(key);
        }

        if (key < node.s4Key) {
            node.stLeft = insertRec(node.stLeft, key);
            node.stLeft.stParent = node;
        } else {
            node.stRight = insertRec(node.stRight, key);
            node.stRight.stParent = node;
        }

        return node;
    }

    public void print() {
        printInOrder(root);
        System.out.println();
        printPreOrder(root);
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
        AVLTree tree = new AVLTree();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of commands: ");
        int numCommands = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < numCommands; i++) {
            System.out.print("Enter the command (insert or print): ");
            String command = scanner.nextLine();

            if (command.equals("insert")) {
                System.out.print("Enter the key to be inserted: ");
                int key = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                tree.insert(key);
            } else if (command.equals("print")) {
                tree.print();
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
