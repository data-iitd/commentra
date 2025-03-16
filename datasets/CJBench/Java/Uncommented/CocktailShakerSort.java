import java.util.Scanner;
public class CocktailShakerSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        CocktailShakerSort sorter = new CocktailShakerSort();
        sorter.sort(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
    public <T extends Comparable<T>> void sort(final T[] array) {
        if (array.length == 0) {
            return;
        }
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            right = performForwardPass(array, left, right);
            left = performBackwardPass(array, left, right);
        }
    }
    private <T extends Comparable<T>> int performForwardPass(final T[] array, final int left, final int right) {
        int lastSwappedIndex = left;
        for (int i = left; i < right; i++) {
            if (array[i].compareTo(array[i + 1]) > 0) {
                swap(array, i, i + 1);
                lastSwappedIndex = i;
            }
        }
        return lastSwappedIndex;
    }
    private <T extends Comparable<T>> int performBackwardPass(final T[] array, final int left, final int right) {
        int lastSwappedIndex = right;
        for (int i = right; i > left; i--) {
            if (array[i].compareTo(array[i - 1]) < 0) {
                swap(array, i - 1, i);
                lastSwappedIndex = i;
            }
        }
        return lastSwappedIndex;
    }
    private <T> void swap(final T[] array, final int i, final int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
