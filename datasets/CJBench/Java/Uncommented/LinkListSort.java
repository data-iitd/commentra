
import java.util.*;
public class LinkListSort {
    public static boolean isSorted(int[] array, int option) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] inputArray = new int[n];
        for (int i = 0; i < n; i++) {
            inputArray[i] = sc.nextInt();
        }
        int sortingChoice = sc.nextInt();
        int[] sortedArray = Arrays.copyOf(inputArray, inputArray.length);
        Arrays.sort(sortedArray);
        Node start = createLinkedList(inputArray);
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
        int[] resultArray = convertLinkedListToArray(start);
        return Arrays.equals(resultArray, sortedArray);
    }
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
    private static int[] convertLinkedListToArray(Node head) {
        List<Integer> list = new ArrayList<>();
        for (Node ptr = head; ptr != null; ptr = ptr.next) {
            list.add(ptr.val);
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
    public static void main(String[] args) {
        if (isSorted(new int[0], 0)) {
            System.out.println("LinkedList is sorted correctly.");
        } else {
            System.out.println("LinkedList is not sorted correctly.");
        }
    }
}
class Node {
    int val;
    Node next;
}
class Task {
    public Node sortByMergeSort(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        int count = countNodes(head);
        int[] array = convertToArray(head, count);
        mergeSort(array, 0, count - 1);
        return convertToList(array);
    }
    private int countNodes(Node head) {
        int count = 0;
        while (head != null) {
            count++;
            head = head.next;
        }
        return count;
    }
    private int[] convertToArray(Node head, int size) {
        int[] array = new int[size];
        int index = 0;
        while (head != null) {
            array[index++] = head.val;
            head = head.next;
        }
        return array;
    }
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
    private void mergeSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
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
class Task1 {
    public Node sortByInsertionSort(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        int count = countNodes(head);
        int[] array = convertToArray(head, count);
        insertionSort(array);
        return convertToList(array);
    }
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
    private int countNodes(Node head) {
        int count = 0;
        while (head != null) {
            count++;
            head = head.next;
        }
        return count;
    }
    private int[] convertToArray(Node head, int size) {
        int[] array = new int[size];
        int index = 0;
        while (head != null) {
            array[index++] = head.val;
            head = head.next;
        }
        return array;
    }
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
class Task2 {
    public Node sortByHeapSort(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        int count = countNodes(head);
        int[] array = convertToArray(head, count);
        heapSort(array);
        return convertToList(array);
    }
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
        if (largest != i) {
            int swap = array[i];
            array[i] = array[largest];
            array[largest] = swap;
            heapify(array, n, largest);
        }
    }
    private int countNodes(Node head) {
        int count = 0;
        while (head != null) {
            count++;
            head = head.next;
        }
        return count;
    }
    private int[] convertToArray(Node head, int size) {
        int[] array = new int[size];
        int index = 0;
        while (head != null) {
            array[index++] = head.val;
            head = head.next;
        }
        return array;
    }
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
