import java.util.Scanner;
public class AVLTreeInteractive {
    private Node root;
    private static class Node {
        private int key;
        private int balance;
        private int height;
        private Node left;
        private Node right;
        private Node parent;
        Node(int k, Node p) {
            key = k;
            parent = p;
        }
    }
    public boolean insert(int key) {
        if (root == null) {
            root = new Node(key, null);
        } else {
            Node n = root;
            Node parent;
            while (true) {
                if (n.key == key) {
                    return false;
                }
                parent = n;
                boolean goLeft = n.key > key;
                n = goLeft ? n.left : n.right;
                if (n == null) {
                    if (goLeft) {
                        parent.left = new Node(key, parent);
                    } else {
                        parent.right = new Node(key, parent);
                    }
                    rebalance(parent);
                    break;
                }
            }
        }
        return true;
    }
    public void delete(int delKey) {
        if (root == null) {
            return;
        }
        Node node = root;
        Node child = root;
        while (child != null) {
            node = child;
            child = delKey >= node.key ? node.right : node.left;
            if (delKey == node.key) {
                deleteNode(node);
                return;
            }
        }
    }
    private void deleteNode(Node node) {
        if (node.left == null && node.right == null) {
            if (node.parent == null) {
                root = null;
            } else {
                Node parent = node.parent;
                if (parent.left == node) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                rebalance(parent);
            }
            return;
        }
        Node child;
        if (node.left != null) {
            child = node.left;
            while (child.right != null) {
                child = child.right;
            }
        } else {
            child = node.right;
            while (child.left != null) {
                child = child.left;
            }
        }
        node.key = child.key;
        deleteNode(child);
    }
    public boolean search(int key) {
        Node result = searchHelper(this.root, key);
        return result != null;
    }
    private Node searchHelper(Node root, int key) {
        if (root == null || root.key == key) {
            return root;
        }
        return key < root.key ? searchHelper(root.left, key) : searchHelper(root.right, key);
    }
    public void display() {
        displayHelper(this.root);
        System.out.println();
    }
    private void displayHelper(Node node) {
        if (node != null) {
            displayHelper(node.left);
            System.out.print(node.key + " ");
            displayHelper(node.right);
        }
    }
    private void rebalance(Node n) {
        setBalance(n);
        if (n.balance == -2) {
            if (height(n.left.left) >= height(n.left.right)) {
                n = rotateRight(n);
            } else {
                n = rotateLeftThenRight(n);
            }
        } else if (n.balance == 2) {
            if (height(n.right.right) >= height(n.right.left)) {
                n = rotateLeft(n);
            } else {
                n = rotateRightThenLeft(n);
            }
        }
        if (n.parent != null) {
            rebalance(n.parent);
        } else {
            root = n;
        }
    }
    private Node rotateLeft(Node a) {
        Node b = a.right;
        b.parent = a.parent;
        a.right = b.left;
        if (a.right != null) {
            a.right.parent = a;
        }
        b.left = a;
        a.parent = b;
        setBalance(a, b);
        return b;
    }
    private Node rotateRight(Node a) {
        Node b = a.left;
        b.parent = a.parent;
        a.left = b.right;
        if (a.left != null) {
            a.left.parent = a;
        }
        b.right = a;
        a.parent = b;
        setBalance(a, b);
        return b;
    }
    private Node rotateLeftThenRight(Node n) {
        n.left = rotateLeft(n.left);
        return rotateRight(n);
    }
    private Node rotateRightThenLeft(Node n) {
        n.right = rotateRight(n.right);
        return rotateLeft(n);
    }
    private int height(Node n) {
        return n == null ? -1 : n.height;
    }
    private void setBalance(Node... nodes) {
        for (Node n : nodes) {
            reheight(n);
            n.balance = height(n.right) - height(n.left);
        }
    }
    private void reheight(Node node) {
        if (node != null) {
            node.height = 1 + Math.max(height(node.left), height(node.right));
        }
    }
    public static void main(String[] args) {
        AVLTreeInteractive tree = new AVLTreeInteractive();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter commands (insert <value>, delete <value>, search <value>, display, exit):");
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            String[] parts = command.split(" ");
            try {
                switch (parts[0]) {
                    case "insert":
                        int valueToInsert = Integer.parseInt(parts[1]);
                        tree.insert(valueToInsert);
                        System.out.println("Inserted: " + valueToInsert);
                        break;
                    case "delete":
                        int valueToDelete = Integer.parseInt(parts[1]);
                        tree.delete(valueToDelete);
                        System.out.println("Deleted: " + valueToDelete);
                        break;
                    case "search":
                        int valueToSearch = Integer.parseInt(parts[1]);
                        System.out.println(tree.search(valueToSearch) ? "Found" : "Not Found");
                        break;
                    case "display":
                        tree.display();
                        break;
                    default:
                        System.out.println("Unknown command");
                }
            } catch (Exception e) {
                System.out.println("Invalid command or input");
            }
        }
        scanner.close();
    }
}
