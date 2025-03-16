
import java.util.Scanner;
public final class LongestIncreasingSubsequence {
    private LongestIncreasingSubsequence() {
    }
    private static int upperBound(int[] ar, int l, int r, int key) {
        while (l < r - 1) {
            int m = (l + r) >>> 1;
            if (ar[m] >= key) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
    public static int lis(int[] array) {
        int len = array.length;
        if (len == 0) {
            return 0;
        }
        int[] tail = new int[len];
        int length = 1;
        tail[0] = array[0];
        for (int i = 1; i < len; i++) {
            if (array[i] < tail[0]) {
                tail[0] = array[i];
            } 
            else if (array[i] > tail[length - 1]) {
                tail[length++] = array[i];
            } 
            else {
                tail[upperBound(tail, -1, length - 1, array[i])] = array[i];
            }
        }
        return length;
    }
    public static int findLISLen(int[] a) {
        final int size = a.length;
        if (size == 0) {
            return 0;
        }
        int[] arr = new int[size];
        arr[0] = a[0];
        int lis = 1;
        for (int i = 1; i < size; i++) {
            int index = binarySearchBetween(arr, lis - 1, a[i]);
            arr[index] = a[i];
            if (index == lis) {
                lis++;
            }
        }
        return lis;
    }
    private static int binarySearchBetween(int[] t, int end, int key) {
        int left = 0;
        int right = end;
        if (key < t[0]) {
            return 0;
        }
        if (key > t[end]) {
            return end + 1;
        }
        while (left < right - 1) {
            final int middle = (left + right) >>> 1;
            if (t[middle] < key) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return right;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int method = scanner.nextInt();
        int result;
        if (method == 1) {
            result = lis(array);
        } else {
            result = findLISLen(array);
        }
        System.out.println("The length of the longest increasing subsequence is: " + result);
    }
}
