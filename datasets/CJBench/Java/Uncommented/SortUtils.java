import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
final class SortUtils {
    private SortUtils() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int i = scanner.nextInt();
        int j = scanner.nextInt();
        swap(array, i, j);
        print(array);
        boolean sorted = isSorted(array);
        System.out.println(sorted);
        int left = scanner.nextInt();
        int right = scanner.nextInt();
        flip(array, left, right);
        print(array);
        scanner.close();
    }
    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }
    public static <T extends Comparable<T>> boolean greater(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) > 0;
    }
    static <T extends Comparable<T>> boolean greaterOrEqual(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) >= 0;
    }
    static void print(List<?> listToPrint) {
        String result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "));
        System.out.println(result);
    }
    static <T> void print(T[] array) {
        System.out.println(Arrays.toString(array));
    }
    public static <T extends Comparable<T>> void flip(T[] array, int left, int right) {
        while (left <= right) {
            swap(array, left++, right--);
        }
    }
    public static <T extends Comparable<T>> boolean isSorted(T[] array) {
        for (int i = 1; i < array.length; i++) {
            if (less(array[i], array[i - 1])) {
                return false;
            }
        }
        return true;
    }
    public static <T extends Comparable<T>> boolean isSorted(List<T> list) {
        for (int i = 1; i < list.size(); i++) {
            if (less(list.get(i), list.get(i - 1))) {
                return false;
            }
        }
        return true;
    }
}
