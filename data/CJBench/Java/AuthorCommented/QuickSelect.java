
import java.util.*;

/**
 * An implementation of the Quickselect algorithm as described
 * <a href="https://en.wikipedia.org/wiki/Median_of_medians">here</a>.
 */
public final class QuickSelect {
    private QuickSelect() {
    }

    /**
     * Selects the {@code n}-th smallest element of {@code list}, i.e., the element that would
     * be at index n if the list was sorted.
     * <p>
     * Calling this function might change the order of elements in {@code list}.
     *
     * @param list the list of elements
     * @param n    the index
     * @param <T>  the type of list elements
     * @return the n-th smallest element in the list
     * @throws IndexOutOfBoundsException if n is less than 0 or greater or equal to
     *                                   the number of elements in the list
     * @throws IllegalArgumentException  if the list is empty
     * @throws NullPointerException      if {@code list} is null
     */
    public static <T extends Comparable<T>> T select(List<T> list, int n) {
        Objects.requireNonNull(list, "The list of elements must not be null.");

        if (list.isEmpty()) {
            throw new IllegalArgumentException("The list of elements must not be empty.");
        }

        if (n < 0 || n >= list.size()) {
            throw new IndexOutOfBoundsException("The index must be between 0 and the size of the list - 1.");
        }

        int index = selectIndex(list, n);
        return list.get(index);
    }

    private static <T extends Comparable<T>> int selectIndex(List<T> list, int n) {
        return selectIndex(list, 0, list.size() - 1, n);
    }

    private static <T extends Comparable<T>> int selectIndex(List<T> list, int left, int right, int n) {
        while (true) {
            if (left == right) {
                return left;
            }
            int pivotIndex = pivot(list, left, right);
            pivotIndex = partition(list, left, right, pivotIndex, n);
            if (n == pivotIndex) {
                return n;
            } else if (n < pivotIndex) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }
    }

    private static <T extends Comparable<T>> int partition(List<T> list, int left, int right, int pivotIndex, int n) {
        T pivotValue = list.get(pivotIndex);
        Collections.swap(list, pivotIndex, right);
        int storeIndex = left;

        for (int i = left; i < right; i++) {
            if (list.get(i).compareTo(pivotValue) < 0) {
                Collections.swap(list, storeIndex, i);
                storeIndex++;
            }
        }

        int storeIndexEq = storeIndex;

        for (int i = storeIndex; i < right; i++) {
            if (list.get(i).compareTo(pivotValue) == 0) {
                Collections.swap(list, storeIndexEq, i);
                storeIndexEq++;
            }
        }

        Collections.swap(list, right, storeIndexEq);

        return (n < storeIndex) ? storeIndex : Math.min(n, storeIndexEq);
    }

    private static <T extends Comparable<T>> int pivot(List<T> list, int left, int right) {
        if (right - left < 5) {
            return partition5(list, left, right);
        }

        for (int i = left; i < right; i += 5) {
            int subRight = Math.min(i + 4, right);
            int median5 = partition5(list, i, subRight);
            Collections.swap(list, median5, left + (i - left) / 5);
        }

        int mid = left + (right - left) / 10 + 1;
        int rightIndex = left + (right - left) / 5;
        return selectIndex(list, left, rightIndex, mid);
    }

    private static <T extends Comparable<T>> int partition5(List<T> list, int left, int right) {
        List<T> sublist = list.subList(left, right + 1);
        sublist.sort(Comparator.naturalOrder());
        return left + (right - left) / 2;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: number of elements in the list
        int n = scanner.nextInt();

        // Input: the elements of the list
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        // Input: the index of the element to find
        int index = scanner.nextInt();

        // Find and print the nth smallest element
        try {
            int result = select(list, index);
            System.out.println("The " + index + "-th smallest element is: " + result);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
