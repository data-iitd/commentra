import java.util.*; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the Main class
    public static boolean isSorted(int[] array, int option) { // Defining the isSorted method that takes an integer array and an option as arguments
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
        int n = sc.nextInt(); // Reading the number of elements in the array from the console
        int[] inputArray = new int[n]; // Creating an integer array of size n to store the input elements
        for (int i = 0; i < n; i++) { // Iterating through the array to read and store the input elements
            inputArray[i] = sc.nextInt();
        }
        int sortingChoice = sc.nextInt(); // Reading the sorting choice from the console
        int[] sortedArray = Arrays.copyOf(inputArray, inputArray.length); // Creating a copy of the input array to store the sorted elements
        Arrays.sort(sortedArray); // Sorting the copied array using the Arrays.sort method
        Node start = createLinkedList(inputArray); // Creating a linked list from the input array using the createLinkedList method
        switch (sortingChoice) { // Switching the sorting choice based on the user input
            case 1:
                start = new Task().sortByMergeSort(start); // Calling the sortByMergeSort method of the Task class to sort the linked list using merge sort
                break;
            case 2:
                start = new Task1().sortByInsertionSort(start); // Calling the sortByInsertionSort method of the Task1 class to sort the linked list using insertion sort
                break;
            case 3:
                start = new Task2().sortByHeapSort(start); // Calling the sortByHeapSort method of the Task2 class to sort the linked list using heap sort
                break;
            default:
                System.out.println("Invalid choice!"); // Printing an error message if the user enters an invalid choice
                return false; // Returning false to indicate that the linked list is not sorted
        }
        int[] resultArray = convertLinkedListToArray(start); // Converting the sorted linked list to an array using the convertLinkedListToArray method
        return Arrays.equals(resultArray, sortedArray); // Comparing the sorted linked list array with the sorted input array using the Arrays.equals method and returning the result
    }
    // Defining the createLinkedList method to create a linked list from an integer array
    private static Node createLinkedList(int[] array) {
        Node start = null, prev = null; // Initializing the start and prev nodes to null
        for (int value : array) { // Iterating through the array to create new nodes and add them to the linked list
            Node fresh = new Node(); // Creating a new Node object
            fresh.val = value; // Setting the value of the new node
            if (start == null) { // If the linked list is empty
                start = fresh; // Setting the start node to the new node
            } else {
                prev.next = fresh; // Setting the next pointer of the previous node to the new node
            }
            prev = fresh; // Setting the previous node to the new node
        }
        return start; // Returning the start node of the linked list
    }
    // Defining the convertLinkedListToArray method to convert a linked list to an integer array
    private static int[] convertLinkedListToArray(Node head) {
        List<Integer> list = new ArrayList<>(); // Creating an empty ArrayList to store the integer values of the linked list
        for (Node ptr = head; ptr != null; ptr = ptr.next) { // Iterating through the linked list to add each value to the ArrayList
            list.add(ptr.val);
        }
        return list.stream().mapToInt(Integer::intValue).toArray(); // Converting the ArrayList to an integer array using the Stream API
    }
    // Defining the main method to test the isSorted method with an empty array
    public static void main(String[] args) {
        if (isSorted(new int[0], 0)) { // Calling the isSorted method with an empty array and an invalid choice to test the error handling
            System.out.println("LinkedList is sorted correctly."); // Printing a message if the linked list is sorted correctly
        } else {
            System.out.println("LinkedList is not sorted correctly."); // Printing a message if the linked list is not sorted correctly
        }
    }
}

// Defining the Node class to represent each node in the linked list
class Node {
    int val; // Defining the value of the node
    Node next; // Defining the next pointer of the node
}

// Defining the Task class to implement merge sort algorithm for the linked list
class Task {
    // Implementing the merge sort algorithm for the linked list
    public Node sortByMergeSort(Node head) {
        // Implementation goes here
    }
    // Helper methods for merge sort algorithm
    private int countNodes(Node head) {
        // Implementation goes here
    }
    private int[] convertToArray(Node head, int size) {
        // Implementation goes here
    }
    private Node convertToList(int[] array) {
        // Implementation goes here
    }
    private void mergeSort(int[] array, int left, int right) {
        // Implementation goes here
    }
    private void merge(int[] array, int left, int mid, int right) {
        // Implementation goes here
    }
}

// Defining the Task1 class to implement insertion sort algorithm for the linked list
class Task1 {
    // Implementing the insertion sort algorithm for the linked list
    public Node sortByInsertionSort(Node head) {
        // Implementation goes here
    }
    // Helper methods for insertion sort algorithm
    private void insertionSort(int[] array) {
        // Implementation goes here
    }
    private int countNodes(Node head) {
        // Implementation goes here
    }
    private int[] convertToArray(Node head, int size) {
        // Implementation goes here
    }
    private Node convertToList(int[] array) {
        // Implementation goes here
    }
}

// Defining the Task2 class to implement heap sort algorithm for the linked list
class Task2 {
    // Implementing the heap sort algorithm for the linked list
    public Node sortByHeapSort(Node head) {
        // Implementation goes here
    }
    // Helper methods for heap sort algorithm
    private void heapSort(int[] array) {
        // Implementation goes here
    }
    private void heapify(int[] array, int n, int i) {
        // Implementation goes here
    }
    private int countNodes(Node head) {
        // Implementation goes here
    }
    private int[] convertToArray(Node head, int size) {
        // Implementation goes here
    }
    private Node convertToList(int[] array) {
        // Implementation goes here
    }
}
