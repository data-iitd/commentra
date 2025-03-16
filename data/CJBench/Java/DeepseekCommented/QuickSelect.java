import java.util.*;

public final class Main {
    private Main() {
    }

    // Public static method to select the n-th smallest element from a list
    public static <T extends Comparable<T>> T select(List<T> list, int n) {
        // Ensure the list is not null
        Objects.requireNonNull(list, "The list of elements must not be null.");
        
        // Check if the list is empty
        if (list.isEmpty()) {
            throw new IllegalArgumentException("The list of elements must not be empty.");
        }
        
        // Check if the index is within the valid range
        if (n < 0 || n >= list.size()) {
            throw new IndexOutOfBoundsException("The index must be between 0 and the size of the list - 1.");
        }
        
        // Find the index of the n-th smallest element
        int index = selectIndex(list, n);
        
        // Return the n-th smallest element
        return list.get(index);
    }

    // Private static method to find the index of the n-th smallest element
    private static <T extends Comparable<T>> int selectIndex(List<T> list, int n) {
        return selectIndex(list, 0, list.size() - 1, n);
    }

    // Private static method to recursively find the index of the n-th smallest element
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

    // Private static method to partition the list around a pivot
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

    // Private static method to select a good pivot for partitioning
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

    // Private static method to partition a sublist of 5 elements
    private static <T extends Comparable<T>> int partition5(List<T> list, int left, int right) {
        List<T> sublist = list.subList(left, right + 1);
        sublist.sort(Comparator.naturalOrder());
        return left + (right - left) / 2;
    }

    // Main method to read input, call the select method, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }
        int index = scanner.nextInt();
        try {
            int result = select(list, index);
            System.out.println("The " + index + "-th smallest element is: " + result);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        scanner.close();
    }
}
