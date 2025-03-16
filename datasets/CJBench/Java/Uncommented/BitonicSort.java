
import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;
public class BitonicSort {
    private enum Direction {
        DESCENDING,
        ASCENDING,
    }
    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) {
            return array;
        }
        final int paddedSize = nextPowerOfTwo(array.length);
        T[] paddedArray = Arrays.copyOf(array, paddedSize);
        final T maxValue = max(array);
        Arrays.fill(paddedArray, array.length, paddedSize, maxValue);
        bitonicSort(paddedArray, 0, paddedSize, Direction.ASCENDING);
        return Arrays.copyOf(paddedArray, array.length);
    }
    private <T extends Comparable<T>> void bitonicSort(final T[] array, final int low, final int cnt, final Direction direction) {
        if (cnt > 1) {
            final int k = cnt / 2;
            bitonicSort(array, low, k, Direction.ASCENDING);
            bitonicSort(array, low + k, cnt - k, Direction.DESCENDING);
            bitonicMerge(array, low, cnt, direction);
        }
    }
    private <T extends Comparable<T>> void bitonicMerge(T[] array, int low, int cnt, Direction direction) {
        if (cnt > 1) {
            final int k = cnt / 2;
            final BiPredicate<T, T> areSorted = (direction == Direction.ASCENDING) ? 
                (a, b) -> a.compareTo(b) < 0 : 
                (a, b) -> a.compareTo(b) > 0;
            for (int i = low; i < low + k; i++) {
                if (!areSorted.test(array[i], array[i + k])) {
                    swap(array, i, i + k);
                }
            }
            bitonicMerge(array, low, k, direction);
            bitonicMerge(array, low + k, cnt - k, direction);
        }
    }
    private static int nextPowerOfTwo(int n) {
        int count = 0;
        if ((n & (n - 1)) == 0) {
            return n;
        }
        while (n != 0) {
            n >>= 1;
            count += 1;
        }
        return 1 << count;
    }
    private static <T extends Comparable<T>> T max(final T[] array) {
        return Arrays.stream(array).max(Comparable::compareTo).orElseThrow();
    }
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        BitonicSort sorter = new BitonicSort();
        Integer[] sortedArray = sorter.sort(array);
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
