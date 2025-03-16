import java.util.Scanner;
public class CycleSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        CycleSort sorter = new CycleSort();
        sorter.sort(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
    public <T extends Comparable<T>> T[] sort(final T[] array) {
        final int length = array.length;
        for (int cycleStart = 0; cycleStart <= length - 2; cycleStart++) {
            T item = array[cycleStart];
            int pos = findPosition(array, cycleStart, item);
            if (pos == cycleStart) {
                continue; 
            }
            item = placeItem(array, item, pos);
            while (pos != cycleStart) {
                pos = findPosition(array, cycleStart, item);
                item = placeItem(array, item, pos);
            }
        }
        return array;
    }
    private <T extends Comparable<T>> int findPosition(final T[] array, final int cycleStart, final T item) {
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < array.length; i++) {
            if (array[i].compareTo(item) < 0) {
                pos++;
            }
        }
        return pos;
    }
    private <T extends Comparable<T>> T placeItem(final T[] array, final T item, int pos) {
        while (item.compareTo(array[pos]) == 0) {
            pos++;
        }
        return replace(array, pos, item);
    }
    private <T extends Comparable<T>> T replace(final T[] array, final int pos, final T item) {
        final T replacedItem = array[pos];
        array[pos] = item;
        return replacedItem;
    }
}
