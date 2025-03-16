import java.util.Scanner;

public class Main {
    // Sorts an array of type T using the dual-pivot quicksort algorithm.
    public static <T extends Comparable<T>> void sort(T[] array) {
        if (array.length > 1) {
            dualPivotQuicksort(array, 0, array.length - 1);
        }
    }

    // Recursively sorts the array using the dual-pivot quicksort algorithm.
    private static <T extends Comparable<T>> void dualPivotQuicksort(final T[] array, final int left, final int right) {
        if (left < right) {
            final int[] pivots = partition(array, left, right);
            dualPivotQuicksort(array, left, pivots[0] - 1);
            dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1);
            dualPivotQuicksort(array, pivots[1] + 1, right);
        }
    }

    // Divides the array into three parts around two pivots and returns their indices.
    private static <T extends Comparable<T>> int[] partition(final T[] array, int left, final int right) {
        if (array[left].compareTo(array[right]) > 0) {
            swap(array, left, right);
        }
        final T pivot1 = array[left];
        final T pivot2 = array[right];
        int pivot1End = left + 1;
        int low = left + 1;
        int high = right - 1;
        while (low <= high) {
            if (array[low].compareTo(pivot1) < 0) {
                swap(array, low, pivot1End);
                pivot1End++;
            } else if (array[low].compareTo(pivot2) >= 0) {
                while (low < high && array[high].compareTo(pivot2) > 0) {
                    high--;
                }
                swap(array, low, high);
                high--;
                if (array[low].compareTo(pivot1) < 0) {
                    swap(array, low, pivot1End);
                    pivot1End++;
                }
            }
            low++;
        }
        pivot1End--;
        high++;
        swap(array, left, pivot1End);
        swap(array, right, high);
        return new int[]{pivot1End, high};
    }

    // Swaps two elements in an array.
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Main method to read input, sort the array, and print the sorted array.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        sort(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
