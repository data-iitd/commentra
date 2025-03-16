import java.util.*;

public class Main {
    // Method to check if the linked list is sorted based on user input
    public static boolean isSorted(int[] array, int option) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        int[] inputArray = new int[n];
        
        // Read the elements of the array from user input
        for (int i = 0; i < n; i++) {
            inputArray[i] = sc.nextInt();
        }
        
        // Read the sorting choice from user input
        int sortingChoice = sc.nextInt();
        
        // Create a copy of the input array and sort it using built-in sort
        int[] sortedArray = Arrays.copyOf(inputArray, inputArray.length);
        Arrays.sort(sortedArray);
        
        // Create a linked list from the input array
        Node start = createLinkedList(inputArray);
        
        // Sort the linked list based on the user's choice of sorting algorithm
        switch (sortingChoice) {
            case 1:
                start = new Task().sortByMergeSort(start);
                break;
            case 2:
                start = new Task1().sortByInsertionSort(start);
                break;
            case 3:
                start = new Task2().sortByHeapSort(start);
                break;
            default:
                // Handle invalid sorting choice
                System.out.println("Invalid choice!");
                return false;
        }
        
        // Convert the sorted linked list back to an array
        int[] resultArray = convertLinkedListToArray(start);
        
        // Compare the sorted linked list array with the built-in sorted array
        return Arrays.equals(resultArray, sortedArray);
    }

    // Method to create a linked list from an array
    private static Node createLinkedList(int[] array) {
        Node start = null, prev = null;
        
        // Iterate through the array and create nodes for the linked list
        for (int value : array) {
            Node fresh = new Node();
            fresh.val = value;
            if (start == null) {
                start = fresh; // Set the start node if it's the first element
            } else {
                prev.next = fresh; // Link the previous node to the current node
            }
            prev = fresh; // Move the previous pointer to the current node
        }
        return start; // Return the head of the linked list
    }

    // Method to convert a linked list back to an array
    private static int[] convertLinkedListToArray(Node head) {
        List<Integer> list = new ArrayList<>();
        
        // Traverse the linked list and add values to the list
        for (Node ptr = head; ptr!= null; ptr = ptr.next) {
            list.add(ptr.val);
        }
        
        // Convert the list to an array and return it
        return list.stream().mapToInt(Integer::intValue).toArray();
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Check if the linked list is sorted and print the result
        if (isSorted(new int[0], 0)) {
            System.out.println("LinkedList is sorted correctly.");
        } else {
            System.out.println("LinkedList is not sorted correctly.");
        }
    }
}

// Node class to represent each element in the linked list
class Node {
    int val; // Value of the node
    Node next; // Pointer to the next node
}

// Class to implement merge sort on a linked list
class Task {
    public Node sortByMergeSort(Node head) {
        // Base case: if the list is empty or has one element
        if (head == null || head.next == null) {
            return head;
        }
        
        // Count the number of nodes in the linked list
        int count = countNodes(head);
        
        // Convert the linked list to an array for sorting
        int[] array = convertToArray(head, count);
        
        // Perform merge sort on the array
        mergeSort(array, 0, count - 1);
        
        // Convert the sorted array back to a linked list
        return convertToList(array);
    }

    // Method to count the number of nodes in the linked list
    private int countNodes(Node head) {
        int count = 0;
        while (head!= null) {
            count++;
            head = head.next;
        }
        return count; // Return the total count of nodes
    }

    // Method to convert a linked list to an array
    private int[] convertToArray(Node head, int size) {
        int[] array = new int[size];
        int index = 0;
        
        // Traverse the linked list and fill the array
        while (head!= null) {
            array[index++] = head.val;
            head = head.next;
        }
        return array; // Return the filled array
    }

    // Method to convert an array back to a linked list
    private Node convertToList(int[] array) {
        Node head = null, tail = null;
        
        // Create nodes for each element in the array
        for (int value : array) {
            Node node = new Node();
            node.val = value;
            if (head == null) {
                head = node; // Set the head if it's the first node
            } else {
                tail.next = node; // Link the previous tail to the current node
            }
            tail = node; // Move the tail pointer to the current node
        }
        return head; // Return the head of the new linked list
    }

    // Method to perform merge sort on an array
    private void mergeSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2; // Find the middle index
            mergeSort(array, left, mid); // Sort the left half
            mergeSort(array, mid + 1, right); // Sort the right half
            merge(array, left, mid, right); // Merge the two halves
        }
    }

    // Method to merge two sorted halves of an array
    private void merge(int[] array, int left, int mid, int right) {
        int[] temp = new int[right - left + 1]; // Temporary array for merging
        int i = left, j = mid + 1, k = 0;
        
        // Merge the two halves into the temporary array
        while (i <= mid && j <= right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++]; // Add smaller element to temp
            } else {
                temp[k++] = array[j++]; // Add smaller element to temp
            }
        }
        
        // Copy remaining elements from the left half, if any
        while (i <= mid) {
            temp[k++] = array[i++];
        }
        
        // Copy remaining elements from the right half, if any
        while (j <= right) {
            temp[k++] = array[j++];
        }
        
        // Copy the sorted elements back to the original array
        for (i = left; i <= right; i++) {
            array[i] = temp[i - left];
        }
    }
}

// Class to implement insertion sort on a linked list
class Task1 {
    public Node sortByInsertionSort(Node head) {
        // Base case: if the list is empty or has one element
        if (head == null || head.next == null) {
            return head;
        }
        
        // Count the number of nodes in the linked list
        int count = countNodes(head);
        
        // Convert the linked list to an array for sorting
        int[] array = convertToArray(head, count);
        
        // Perform insertion sort on the array
        insertionSort(array);
        
        // Convert the sorted array back to a linked list
        return convertToList(array);
    }

    // Method to perform insertion sort on an array
    private void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i]; // Current element to be inserted
            int j = i - 1;
            // Shift elements of array that are greater than key
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key; // Insert the key at the correct position
        }
    }

    // Method to count the number of nodes in the linked list
    private int countNodes(Node head) {
        int count = 0;
        while (head!= null) {
            count++;
            head = head.next;
        }
        return count; // Return the total count of nodes
    }

    // Method to convert a linked list to an array
    private int[] convertToArray(Node head, int size) {
        int[] array = new int[size];
        int index = 0;
        
        // Traverse the linked list and fill the array
        while (head!= null) {
            array[index++] = head.val;
            head = head.next;
        }
        return array; // Return the filled array
    }

    // Method to convert an array back to a linked list
    private Node convertToList(int[] array) {
        Node head = null, tail = null;
        
        // Create nodes for each element in the array
        for (int value : array) {
            Node node = new Node();
            node.val = value;
            if (head == null) {
                head = node; // Set the head if it's the first node
            } else {
                tail.next = node; // Link the previous tail to the current node
            }
            tail = node; // Move the tail pointer to the current node
        }
        return head; // Return the head of the new linked list
    }
}

// Class to implement heap sort on a linked list
class Task2 {
    public Node sortByHeapSort(Node head) {
        // Base case: if the list is empty or has one element
        if (head == null || head.next == null) {
            return head;
        }
        
        // Count the number of nodes in the linked list
        int count = countNodes(head);
        
        // Convert the linked list to an array for sorting
        int[] array = convertToArray(he