public class BinarySearchTree {
    static class Node {
        Node parent;
        Node left;
        Node right;
        int key;
    }

    public static void insert(Node root, int key) {
        Node parentNode = null;
        Node indexNode = root;
        Node insertNode = newNode(key);

        while (indexNode != null) {
            parentNode = indexNode;
            if (insertNode.key < indexNode.key) {
                indexNode = indexNode.left;
            } else {
                indexNode = indexNode.right;
            }
        }
        insertNode.parent = parentNode;

        if (parentNode == null) {
            root = insertNode;
        } else if (key < parentNode.key) {
            parentNode.left = insertNode;
        } else {
            parentNode.right = insertNode;
        }
    }

    public static void printTree(Node root) {
        printInOrder(root);
        System.out.println();
        printPreOrder(root);
        System.out.println();
    }

    private static void printPreOrder(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(" " + node.key);
        printPreOrder(node.left);
        printPreOrder(node.right);
    }

    private static void printInOrder(Node node) {
        if (node == null) {
            return;
        }

        printInOrder(node.left);
        System.out.print(" " + node.key);
        printInOrder(node.right);
    }

    private static Node newNode(int key) {
        Node node = new Node();
        node.parent = null;
        node.left = null;
        node.right = null;
        node.key = key;
        return node;
    }

    public static void main(String[] args) {
        Node root = null;
        Scanner scanner = new Scanner(System.in);
        int numCommands = scanner.nextInt();

        for (int i = 0; i < numCommands; i++) {
            String command = scanner.next();
            if (command.equals("insert")) {
                int insertKey = scanner.nextInt();
                insert(root, insertKey);
            } else {
                printTree(root);
            }
        }
    }
}
