import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static final int NUM_MAX = 1000;
    private static final int NUM2_MAX = NUM_MAX * NUM_MAX;
    private static final int RANK_MAX = 3000;
    private static final long VAL_MAX = (long) (1e+10);
    private static final long SUM_MAX = VAL_MAX * 3;

    static class Range {
        int start;
        int end;

        Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    // Function to read an array of 4 integers from the standard input
    static void getInt4(Scanner scanner, int[] arr) {
        for (int i = 0; i < 4; i++) {
            arr[i] = scanner.nextInt();
        }
    }

    // Function to read an array of 64-bit integers from the standard input
    static void fgetArray(Scanner scanner, long[] arr, int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextLong();
        }
    }

    // Comparator function for sorting in ascending order
    static int asc(long a1, long a2) {
        return Long.compare(a1, a2);
    }

    // Comparator function for sorting in descending order
    static int desc(long a1, long a2) {
        return Long.compare(a2, a1);
    }

    // Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
    static int lowerBound(long[] arr, Range r, long key) {
        int low = r.start;
        int high = r.end;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] input = new int[4];
        getInt4(scanner, input);
        int x = input[0], y = input[1], z = input[2], rank = input[3];

        long[] xrr = new long[NUM_MAX];
        long[] yrr = new long[NUM_MAX];
        long[] zrr = new long[NUM_MAX];

        fgetArray(scanner, xrr, x);
        fgetArray(scanner, yrr, y);
        fgetArray(scanner, zrr, z);

        long minSum = VAL_MAX + 1;
        long maxSum = 0;

        for (int i = 0; i < z; i++) {
            minSum = Math.min(minSum, zrr[i]);
            maxSum += zrr[i];
        }

        long[] pair = new long[NUM2_MAX];
        int idx = 0;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }

        Arrays.sort(pair, 0, idx);
        minSum += pair[0];
        maxSum += pair[idx - 1];

        int[] cache = new int[NUM_MAX];
        int[] cntMap = new int[NUM_MAX];
        long[] ans = new long[RANK_MAX];
        int size = x * y * z;
        long prev = minSum;

        for (int r = rank; r >= 1; r--) {
            long low = prev - 1;
            long high = maxSum + 1;

            while (low + 1 < high) {
                long mid = (low + high) / 2;

                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    Range range = new Range(cache[i] - 1, idx);
                    int tmp = lowerBound(pair, range, mid - pivot);
                    cntMap[i] = tmp;
                }

                if (sum(cntMap, z) >= size - r) {
                    low = mid;
                } else {
                    high = mid;
                }
            }

            ans[r - 1] = low;
            if (low == maxSum) break;
            prev = low;
        }

        for (int i = 0; i < rank; i++) {
            System.out.println(ans[i] == 0 ? maxSum : ans[i]);
        }

        scanner.close();
    }

    // Helper function to sum an array
    static int sum(int[] arr, int size) {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }
}

// <END-OF-CODE>
