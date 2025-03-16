import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    private static final Random RANDOM = new Random();

    // This method finds the k-th maximum element in an array.
    public static int findKthMax(int[] array, int k) {
        if (k <= 0 || k > array.length) {
            throw new IllegalArgumentException("k must be between 1 and the size of the array");
        }
        return quickSelect(array, 0, array.length - 1, array.length - k);
    }

    // This method uses the Quickselect algorithm to find the k-th smallest element in the array.
    private static int quickSelect(int[] array, int left, int right, int kSmallest) {
        if (left == right) {
            return array[left];
        }
        int pivotIndex = left + RANDOM.nextInt(right - left + 1);
        pivotIndex = partition(array, left, right, pivotIndex);
        if (kSmallest == pivotIndex) {
            return array[kSmallest];
        } else if (kSmallest < pivotIndex) {
            return quickSelect(array, left, pivotIndex - 1, kSmallest);
        } else {
            return quickSelect(array, pivotIndex + 1, right, kSmallest);
        }
    }

    // This method partitions the array around a pivot element.
    private static int partition(int[] array, int left, int right, int pivotIndex) {
        int pivotValue = array[pivotIndex];
        swap(array, pivotIndex, right);
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (array[i] < pivotValue) {
                swap(array, storeIndex, i);
                storeIndex++;
            }
        }
        swap(array, storeIndex, right);
        return storeIndex;
    }

    // This method swaps two elements in the array.
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // This is the entry point of the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int n = scanner.nextInt();
            if (n <= 0) {
                System.out.println("Array size must be positive.");
                return;
            }
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }
            int k = scanner.nextInt();
            if (k <= 0 || k > n) {
                System.out.println("Error: k must be between 1 and the size of the array.");
                return;
            }
            int result = findKthMax(array, k);
            System.out.println("The " + k + "-th largest element is: " + result);
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
