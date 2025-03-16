import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * <h1> Implementation of the Tree Sort algorithm</h1>
 *
 * <p>
 * Tree Sort: A sorting algorithm which constructs a Binary Search Tree using
 * the unsorted data and then outputs the data by inorder traversal of the tree.
 *
 * Reference: https://en.wikipedia.org/wiki/Tree_sort
 * </p>
 *
 * @author Madhur Panwar (https://github.com/mdrpanwar)
 */
public class TreeSort {

    // Node class for BST
    static class Node<T extends Comparable<T>> {
        T data;
        Node<T> left, right;

        Node(T data) {
            this.data = data;
        }
    }

    // Generic BST class
    static class BST<T extends Comparable<T>> {
        Node<T> root;

        void add(T data) {
            root = addRecursive(root, data);
        }

        private Node<T> addRecursive(Node<T> node, T data) {
            if (node == null) {
                return new Node<>(data);
            }
            if (data.compareTo(node.data) < 0) {
                node.left = addRecursive(node.left, data);
            } else {
                node.right = addRecursive(node.right, data);
            }
            return node;
        }

        List<T> inOrderTraversal() {
            List<T> result = new ArrayList<>();
            inOrderTraversal(root, result);
            return result;
        }

        private void inOrderTraversal(Node<T> node, List<T> result) {
            if (node != null) {
                inOrderTraversal(node.left, result);
                result.add(node.data);
                inOrderTraversal(node.right, result);
            }
        }
    }

    // Sort method for arrays
    public <T extends Comparable<T>> T[] sort(T[] unsortedArray) {
        BST<T> tree = new BST<>();
        for (T element : unsortedArray) {
            tree.add(element);
        }
        List<T> sortedList = tree.inOrderTraversal();
        return sortedList.toArray(unsortedArray);
    }

    // Sort method for lists
    public <T extends Comparable<T>> List<T> sort(List<T> unsortedList) {
        BST<T> tree = new BST<>();
        for (T element : unsortedList) {
            tree.add(element);
        }
        return tree.inOrderTraversal();
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TreeSort treeSort = new TreeSort();


        int type = scanner.nextInt();
        scanner.nextLine(); // Consume newline


        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        if (type == 1) {
            Integer[] array = new Integer[n];

            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }
            array = treeSort.sort(array);
            System.out.println("Sorted Array:");
            for (Integer num : array) {
                System.out.print(num + " ");
            }
        } else if (type == 2) {
            String[] array = new String[n];

            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextLine();
            }
            array = treeSort.sort(array);
            System.out.println("Sorted Array:");
            for (String str : array) {
                System.out.print(str + " ");
            }
        } else {
            System.out.println("Invalid type entered.");
        }
        scanner.close();
    }
}
