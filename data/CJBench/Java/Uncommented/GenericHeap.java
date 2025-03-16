import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class GenericHeap<T extends Comparable<T>> {
    private final ArrayList<T> data = new ArrayList<>();
    private final HashMap<T, Integer> map = new HashMap<>();
    public void add(T item) {
        if (item == null) {
            throw new IllegalArgumentException("Cannot insert null into the heap.");
        }
        this.data.add(item);
        map.put(item, this.data.size() - 1);
        upHeapify(this.data.size() - 1);
    }
    private void upHeapify(int ci) {
        int pi = (ci - 1) / 2;
        if (ci > 0 && isLarger(this.data.get(ci), this.data.get(pi)) > 0) {
            swap(pi, ci);
            upHeapify(pi);
        }
    }
    public int size() {
        return this.data.size();
    }
    public boolean isEmpty() {
        return this.size() == 0;
    }
    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        swap(0, this.size() - 1);
        T rv = this.data.remove(this.size() - 1);
        map.remove(rv);
        downHeapify(0);
        return rv;
    }
    private void downHeapify(int pi) {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int maxi = pi;
        if (lci < this.size() && isLarger(this.data.get(lci), this.data.get(maxi)) > 0) {
            maxi = lci;
        }
        if (rci < this.size() && isLarger(this.data.get(rci), this.data.get(maxi)) > 0) {
            maxi = rci;
        }
        if (maxi != pi) {
            swap(pi, maxi);
            downHeapify(maxi);
        }
    }
    public T get() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return this.data.get(0);
    }
    private int isLarger(T t, T o) {
        return t.compareTo(o);
    }
    private void swap(int i, int j) {
        T ith = this.data.get(i);
        T jth = this.data.get(j);
        this.data.set(i, jth);
        this.data.set(j, ith);
        map.put(ith, j);
        map.put(jth, i);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GenericHeap<Integer> heap = new GenericHeap<>();
        int operations = scanner.nextInt();
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    int element = scanner.nextInt();
                    heap.add(element);
                    System.out.println("Added: " + element);
                    break;
                case 2:
                    try {
                        System.out.println("Removed: " + heap.remove());
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 3:
                    try {
                        System.out.println("Max element: " + heap.get());
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 4:
                    System.out.println("Heap size: " + heap.size());
                    break;
                case 5:
                    System.out.println("Heap is empty: " + heap.isEmpty());
                    break;
                default:
                    System.out.println("Invalid operation.");
            }
        }
        scanner.close();
    }
}
