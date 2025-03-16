import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class Main {
    private static final int BUCKET_DIVISOR = 10;
    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) {
            return array;
        }
        T min = findMin(array);
        T max = findMax(array);
        int numberOfBuckets = calculateNumberOfBuckets(array.length);
        List<List<T>> buckets = initializeBuckets(numberOfBuckets);
        distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets);
        return concatenateBuckets(buckets, array);
    }
    private int calculateNumberOfBuckets(final int arrayLength) {
        return Math.max(arrayLength / BUCKET_DIVISOR, 1);
    }
    private <T extends Comparable<T>> List<List<T>> initializeBuckets(int numberOfBuckets) {
        List<List<T>> buckets = new ArrayList<>(numberOfBuckets);
        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(new ArrayList<>());
        }
        return buckets;
    }
    private <T extends Comparable<T>> void distributeElementsIntoBuckets(T[] array, List<List<T>> buckets, final T min, final T max, final int numberOfBuckets) {
        for (final T element : array) {
            int bucketIndex = hash(element, min, max, numberOfBuckets);
            buckets.get(bucketIndex).add(element);
        }
    }
    private <T extends Comparable<T>> T[] concatenateBuckets(Iterable<List<T>> buckets, T[] array) {
        int index = 0;
        for (List<T> bucket : buckets) {
            Collections.sort(bucket);
            for (T element : bucket) {
                array[index++] = element;
            }
        }
        return array;
    }
    private <T extends Comparable<T>> int hash(final T element, final T min, final T max, final int numberOfBuckets) {
        double range = max.compareTo(min);
        double normalizedValue = element.compareTo(min) / range;
        return (int) (normalizedValue * (numberOfBuckets - 1));
    }
    private <T extends Comparable<T>> T findMin(T[] array) {
        T min = array[0];
        for (T element : array) {
            if (element.compareTo(min) < 0) {
                min = element;
            }
        }
        return min;
    }
    private <T extends Comparable<T>> T findMax(T[] array) {
        T max = array[0];
        for (T element : array) {
            if (element.compareTo(max) > 0) {
                max = element;
            }
        }
        return max;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Double[] array = new Double[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextDouble();
        }
        Main sorter = new Main();
        Double[] sortedArray = sorter.sort(array);
        for (double num : sortedArray) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
