
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Represents a node in a binary search tree (BST)
    static class Node<T extends Comparable<T>> {
        T data;
        Node<T> left, right;
        Node(T data) {
            this.data = data;
        }
    }

    // Represents a binary search tree (BST)
    static class BST<T extends Comparable<T>> {
        Node<T> root;

        // Adds a new element to the BST
        void add(T data) {
            root = addRecursive(root, data);
        }

        // Recursive helper method to add a new element to the BST
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

        // Performs an in-order traversal of the BST and returns the sorted list of elements
        List<T> inOrderTraversal() {
            List<T> result = new ArrayList<>();
            inOrderTraversal(root, result);
            return result;
        }

        // Recursive helper method for in-order traversal
        private void inOrderTraversal(Node<T> node, List<T> result) {
            if (node != null) {
                inOrderTraversal(node.left, result);
                result.add(node.data);
                inOrderTraversal(node.right, result);
            }
        }
    }

    // Sorts an array of type T using a BST
    public <T extends Comparable<T>> T[] sort(T[] unsortedArray) {
        BST<T> tree = new BST<>();
        for (T element : unsortedArray) {
            tree.add(element);
        }
        List<T> sortedList = tree.inOrderTraversal();
        return sortedList.toArray(unsortedArray);
    }

    // Sorts a list of type T using a BST
    public <T extends Comparable<T>> List<T> sort(List<T> unsortedList) {
        BST<T> tree = new BST<>();
        for (T element : unsortedList) {
            tree.add(element);
        }
        return tree.inOrderTraversal();
    }

    // Main method to handle user input and output
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main treeSort = new Main();
        int type = scanner.nextInt();
        scanner.nextLine(); 
        int n = scanner.nextInt();
        scanner.nextLine(); 
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

This code provides a clear structure with comments explaining each logical block, making it easier to understand and maintain.