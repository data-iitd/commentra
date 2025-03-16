import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class SplayTree {
    public static final TreeTraversal IN_ORDER = new InOrderTraversal();
    private Node root;
    public boolean isEmpty() {
        return root == null;
    }
    public void insert(final int key) {
        root = insertRec(root, key);
        root = splay(root, key);
    }
    public boolean search(int key) {
        root = splay(root, key);
        return root != null && root.key == key;
    }
    public void delete(final int key) {
        if (isEmpty()) {
            throw new EmptyTreeException("Cannot delete from an empty tree");
        }
        root = splay(root, key);
        if (root.key != key) {
            return;
        }
        if (root.left == null) {
            root = root.right;
        } else {
            Node temp = root;
            root = splay(root.left, findMax(root.left).key);
            root.right = temp.right;
        }
    }
    public List<Integer> traverse(TreeTraversal traversal) {
        List<Integer> result = new ArrayList<>();
        traversal.traverse(root, result);
        return result;
    }
    private Node findMax(Node root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }
    private Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        return y;
    }
    private Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        return y;
    }
    private Node splay(Node root, final int key) {
        if (root == null || root.key == key) {
            return root;
        }
        if (root.key > key) {
            if (root.left == null) {
                return root;
            }
            if (root.left.key > key) {
                root.left.left = splay(root.left.left, key);
                root = rotateRight(root);
            } else if (root.left.key < key) {
                root.left.right = splay(root.left.right, key);
                if (root.left.right != null) {
                    root.left = rotateLeft(root.left);
                }
            }
            return (root.left == null) ? root : rotateRight(root);
        } else {
            if (root.right == null) {
                return root;
            }
            if (root.right.key > key) {
                root.right.left = splay(root.right.left, key);
                if (root.right.left != null) {
                    root.right = rotateRight(root.right);
                }
            } else if (root.right.key < key) {
                root.right.right = splay(root.right.right, key);
                root = rotateLeft(root);
            }
            return (root.right == null) ? root : rotateLeft(root);
        }
    }
    private Node insertRec(Node root, final int key) {
        if (root == null) {
            return new Node(key);
        }
        if (key < root.key) {
            root.left = insertRec(root.left, key);
        } else if (key > root.key) {
            root.right = insertRec(root.right, key);
        } else {
            throw new DuplicateKeyException("Duplicate key: " + key);
        }
        return root;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SplayTree splayTree = new SplayTree();
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    int valueToInsert = scanner.nextInt();
                    splayTree.insert(valueToInsert);
                    System.out.println("Inserted " + valueToInsert);
                    break;
                case 2:
                    int valueToDelete = scanner.nextInt();
                    try {
                        splayTree.delete(valueToDelete);
                        System.out.println("Deleted " + valueToDelete);
                    } catch (EmptyTreeException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3:
                    int valueToSearch = scanner.nextInt();
                    boolean found = splayTree.search(valueToSearch);
                    System.out.println(found ? "Found " + valueToSearch : "Not found");
                    break;
                case 4:
                    System.out.println("In-order traversal:");
                    System.out.println(splayTree.traverse(IN_ORDER));
                    break;
                default:
                    System.out.println("Invalid operation.");
            }
        }
        scanner.close();
    }
    private static class Node {
        final int key;
        Node left;
        Node right;
        Node(int key) {
            this.key = key;
            left = null;
            right = null;
        }
    }
    public static class EmptyTreeException extends RuntimeException {
        public EmptyTreeException(String message) {
            super(message);
        }
    }
    public static class DuplicateKeyException extends RuntimeException {
        public DuplicateKeyException(String message) {
            super(message);
        }
    }
    public interface TreeTraversal {
        void traverse(Node root, List<Integer> result);
    }
    private static final class InOrderTraversal implements TreeTraversal {
        public void traverse(Node root, List<Integer> result) {
            if (root != null) {
                traverse(root.left, result);
                result.add(root.key);
                traverse(root.right, result);
            }
        }
    }
}
