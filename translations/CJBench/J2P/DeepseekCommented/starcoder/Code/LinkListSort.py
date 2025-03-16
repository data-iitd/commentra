import java.util.*;
public class Main {
    // Main method where the program execution starts.
    public static void main(String[] args) {
        if (isSorted(new int[0], 0)) {
            System.out.println("LinkedList is sorted correctly.");
        } else {
            System.out.println("LinkedList is not sorted correctly.");
        }
    }

    // Checks if the linked list is sorted based on the user's choice of sorting algorithm.
    public static boolean isSorted(int[] array, int option) {
        Scanner sc = new Scanner(System.in);
        // Read the size of the array.
        int n = sc.nextInt();
        int[] inputArray = new int[n];
        // Read the elements of the array.
        for (int i = 0; i < n; i++) {
            inputArray[i] = sc.nextInt();
        }
        // Read the sorting choice.
        int sortingChoice = sc.nextInt();
        // Create a copy of the input array to compare with the sorted result.
        int[] sortedArray = Arrays.copyOf(inputArray, inputArray.length);
        Arrays.sort(sortedArray);
        // Create a linked list from the input array.
        Node start = createLinkedList(inputArray);
        // Sort the linked list based on the user's choice.
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
                System.out.println("Invalid choice!");
                return false;
        }
        // Convert the sorted linked list back to an array.
        int[] resultArray = convertLinkedListToArray(start);
        // Compare the sorted linked list with the sorted array.
        return Arrays.equals(resultArray, sortedArray);
    }

    // Converts an array into a linked list.
    private static Node createLinkedList(int[] array) {
        Node start = null, prev = null;
        for (int value : array) {
            Node fresh = new Node();
            fresh.val = value;
            if (start == null) {
                start = fresh;
            } else {
                prev.next = fresh;
            }
            prev = fresh;
        }
        return start;
    }

    // Converts a linked list back into an array.
    private static int[] convertLinkedListToArray(Node head) {
        List<Integer> list = new ArrayList<>();
        for (Node ptr = head; ptr!= null; ptr = ptr.next) {
            list.add(ptr.val);
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }

    // Node class definition for a linked list.
    static class Node {
        int val;
        Node next;
    }

    // Task class implementing Merge Sort for linked lists.
    static class Task {
        public Node sortByMergeSort(Node head) {
            if (head == null || head.next == null) {
                return head;
            }
            int count = countNodes(head);
            int[] array = convertToArray(head, count);
            mergeSort(array, 0, count - 1);
            return convertToList(array);
        }

        // Counts the number of nodes in the linked list.
        private int countNodes(Node head) {
            int count = 0;
            while (head!= null) {
                count++;
                head = head.next;
            }
            return count;
        }

        // Converts a linked list to an array.
        private int[] convertToArray(Node head, int size) {
            int[] array = new int[size];
            int index = 0;
            while (head!= null) {
                array[index++] = head.val;
                head = head.next;
            }
            return array;
        }

        // Converts an array to a linked list.
        private Node convertToList(int[] array) {
            Node head = null, tail = null;
            for (int value : array) {
                Node node = new Node();
                node.val = value;
                if (head == null) {
                    head = node;
                } else {
                    tail.next = node;
                }
                tail = node;
            }
            return head;
        }

        // Merge Sort implementation for arrays.
        private void mergeSort(int[] array, int left, int right) {
            if (left < right) {
                int mid = (left + right) / 2;
                mergeSort(array, left, mid);
                mergeSort(array, mid + 1, right);
                merge(array, left, mid, right);
            }
        }

        // Merges two sorted subarrays.
        private void merge(int[] array, int left, int mid, int right) {
            int[] temp = new int[right - left + 1];
            int i = left, j = mid + 1, k = 0;
            while (i <= mid && j <= right) {
                if (array[i] <= array[j]) {
                    temp[k++] = array[i++];
                } else {
                    temp[k++] = array[j++];
                }
            }
            while (i <= mid) {
                temp[k++] = array[i++];
            }
            while (j <= right) {
                temp[k++] = array[j++];
            }
            for (i = left; i <= right; i++) {
                array[i] = temp[i - left];
            }
        }
    }

    // Task1 class implementing Insertion Sort for linked lists.
    static class Task1 {
        public Node sortByInsertionSort(Node head) {
            if (head == null || head.next == null) {
                return head;
            }
            int count = countNodes(head);
            int[] array = convertToArray(head, count);
            insertionSort(array);
            return convertToList(array);
        }

        // Insertion Sort implementation for arrays.
        private void insertionSort(int[] array) {
            for (int i = 1; i < array.length; i++) {
                int key = array[i];
                int j = i - 1;
                while (j >= 0 && array[j] > key) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
            }
        }

        // Counts the number of nodes in the linked list.
        private int countNodes(Node head) {
            int count = 0;
            while (head!= null) {
                count++;
                head = head.next;
            }
            return count;
        }

        // Converts a linked list to an array.
        private int[] convertToArray(Node head, int size) {
            int[] array = new int[size];
            int index = 0;
            while (head!= null) {
                array[index++] = head.val;
                head = head.next;
            }
            return array;
        }

        // Converts an array to a linked list.
        private Node convertToList(int[] array) {
            Node head = null, tail = null;
            for (int value : array) {
                Node node = new Node();
                node.val = value;
                if (head == null) {
                    head = node;
                } else {
                    tail.next = node;
                }
                tail = node;
            }
            return head;
        }
    }

    // Task2 class implementing Heap Sort for linked lists.
    static class Task2 {
        public Node sortByHeapSort(Node head) {
            if (head == null || head.next == null) {
                return head;
            }
            int count = countNodes(head);
            int[] array = convertToArray(head, count);
            heapSort(array);
            return convertToList(array);
        }

        // Heap Sort implementation for arrays.
        private void heapSort(int[] array) {
            int n = array.length;
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(array, n, i);
            }
            for (int i = n - 1; i >= 0; i--) {
                int temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                heapify(array, i, 0);
            }
        }

        // Heapify implementation for arrays.
        private void heapify(int[] array, int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && array[left] > array[largest]) {
                largest = left;
            }
            if (right < n && array[right] > array[largest]) {
                largest = right;
            }
            if (largest!= i) {
                int swap = array[i];
                array[i] = array[largest];
                array[largest] = swap;
                heapify(array, n, largest);
            }
        }

        // Counts the number of nodes in the linked list.
        private int countNodes(Node head) {
            int count = 0;
            while (head!= null) {
                count++;
                head = head.next;
            }
            return count;
        }

        // Converts a linked list to an array.
        private int[] convertToArray(Node head, int size) {
            int[] array = new int[size];
            int index = 0;
            while (head!= null) {
                array[index++] = head.val;
                head = head.next;
            }
            return array;
        }

        // Converts an array to a linked list.
        private Node convertToList(int[] array) {
            Node head = null, tail = null;
            for (int value : array) {
                Node node = new Node();
                node.val = value;
                if (head == null) {
                    head = node;
                } else {
                    tail.next = node;
                }
                tail = node;
            }
            return head;
        }
    }
}
