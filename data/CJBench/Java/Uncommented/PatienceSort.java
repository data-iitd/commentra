import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
public class PatienceSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        patienceSort(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
    public static <T extends Comparable<T>> T[] patienceSort(T[] array) {
        if (array.length == 0) {
            return array;
        }
        final List<List<T>> piles = formPiles(array);
        final PriorityQueue<PileNode<T>> pq = mergePiles(piles);
        extractPiles(array, pq);
        return array;
    }
    private static <T extends Comparable<T>> List<List<T>> formPiles(final T[] array) {
        final List<List<T>> piles = new ArrayList<>();
        final List<T> lastElements = new ArrayList<>();
        for (T x : array) {
            int pos = Collections.binarySearch(lastElements, x);
            if (pos < 0) {
                pos = -pos - 1;
            }
            if (pos < piles.size()) {
                piles.get(pos).add(x);
                lastElements.set(pos, x);
            } else {
                List<T> newPile = new ArrayList<>();
                newPile.add(x);
                piles.add(newPile);
                lastElements.add(x);
            }
        }
        return piles;
    }
    private static <T extends Comparable<T>> PriorityQueue<PileNode<T>> mergePiles(final Iterable<List<T>> piles) {
        PriorityQueue<PileNode<T>> pq = new PriorityQueue<>();
        for (List<T> pile : piles) {
            pq.add(new PileNode<>(pile.remove(pile.size() - 1), pile));
        }
        return pq;
    }
    private static <T extends Comparable<T>> void extractPiles(final T[] array, final PriorityQueue<PileNode<T>> pq) {
        int index = 0;
        while (!pq.isEmpty()) {
            PileNode<T> node = pq.poll();
            array[index++] = node.value;
            if (!node.pile.isEmpty()) {
                pq.add(new PileNode<>(node.pile.remove(node.pile.size() - 1), node.pile));
            }
        }
    }
    private static class PileNode<T extends Comparable<T>> implements Comparable<PileNode<T>> {
        final T value;
        final List<T> pile;
        public PileNode(T value, List<T> pile) {
            this.value = value;
            this.pile = pile;
        }
        @Override
        public int compareTo(PileNode<T> other) {
            return this.value.compareTo(other.value);
        }
    }
}
