
import java.util.Scanner;

/**
 * Implementation of a Segment Tree to efficiently perform range sum queries and point updates.
 */
public class SegmentTree {
    private int[] segTree;
    private int n;
    private int[] arr;

    /**
     * Constructor that initializes the segment tree.
     *
     * @param n   The size of the input array.
     * @param arr The input array.
     */
    public SegmentTree(int n, int[] arr) {
        this.n = n;
        // Calculate the height of the segment tree
        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
        // Calculate the maximum size of the segment tree
        int segSize = 2 * (int) Math.pow(2, x) - 1;

        this.segTree = new int[segSize];
        this.arr = arr;
        constructTree(arr, 0, n - 1, 0);
    }

    /**
     * Recursively constructs the segment tree.
     *
     * @param arr   The input array.
     * @param start The starting index of the current segment.
     * @param end   The ending index of the current segment.
     * @param index The current index in the segment tree array.
     * @return The sum of the current segment.
     */
    private int constructTree(int[] arr, int start, int end, int index) {
        if (start == end) {
            this.segTree[index] = arr[start];
            return arr[start];
        }

        int mid = start + (end - start) / 2;
        this.segTree[index] = constructTree(arr, start, mid, index * 2 + 1) +
                constructTree(arr, mid + 1, end, index * 2 + 2);
        return this.segTree[index];
    }

    /* A function which will update the value at a index i. This will be called by the
    update function internally*/
    private void updateTree(int start, int end, int index, int diff, int segIndex) {
        if (index < start || index > end) {
            return;
        }

        this.segTree[segIndex] += diff;
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateTree(start, mid, index, diff, segIndex * 2 + 1);
            updateTree(mid + 1, end, index, diff, segIndex * 2 + 2);
        }
    }

    /**
     * Updates the value of a specific index in the input array.
     *
     * @param index The index to update.
     * @param value The new value.
     */
    public void update(int index, int value) {
        if (index < 0 || index >= n) {
            return;
        }

        int diff = value - arr[index];
        arr[index] = value;
        updateTree(0, n - 1, index, diff, 0);
    }

    /* A function to get the sum of the elements from index l to index r. This will be called
     * internally*/
    private int getSumTree(int start, int end, int qStart, int qEnd, int segIndex) {
        if (qStart <= start && qEnd >= end) {
            return this.segTree[segIndex];
        }

        if (qStart > end || qEnd < start) {
            return 0;
        }

        int mid = start + (end - start) / 2;
        return (getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) +
                getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2));
    }

    /**
     * Queries the sum of a range in the input array.
     *
     * @param start The starting index of the range.
     * @param end   The ending index of the range.
     * @return The sum of the range.
     */
    public int getSum(int start, int end) {
        if (start < 0 || end >= n || start > end) {
            return 0;
        }
        return getSumTree(0, n - 1, start, end, 0);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        SegmentTree segmentTree = new SegmentTree(n, arr);

        int q = scanner.nextInt();

        for (int i = 0; i < q; i++) {
            int choice = scanner.nextInt();

            if (choice == 1) {
                int start = scanner.nextInt();
                int end = scanner.nextInt();
                System.out.println("Sum of range [" + start + ", " + end + "] is: " + segmentTree.getSum(start, end));
            } else if (choice == 2) {
                int index = scanner.nextInt();
                int value = scanner.nextInt();
                segmentTree.update(index, value);
                System.out.println("Value updated.");
            } else {
                System.out.println("Invalid operation.");
            }
        }

        scanner.close();
    }
}
