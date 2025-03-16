import java.util.Arrays;
import java.util.Scanner;

public class Main {

    // Function to read four integers from standard input
    static void getInt4(int[] a) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 4; i++) {
            a[i] = scanner.nextInt();
        }
    }

    // Function to read an array of long from standard input
    static long[] fgetArray(int size) {
        Scanner scanner = new Scanner(System.in);
        long[] arr = new long[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextLong();
        }
        return arr;
    }

    // Constants defining maximum sizes for arrays and ranks
    static final int NUM_MAX = 1000;
    static final int NUM2_MAX = NUM_MAX * NUM_MAX;
    static final int RANK_MAX = 3000;

    // Comparison function for ascending order used in qsort
    static int asc(final long a1, final long a2) {
        return Long.compare(a1, a2);
    }

    // Comparison function for descending order used in qsort
    static int desc(final long a1, final long a2) {
        return Long.compare(a2, a1);
    }

    // Constants defining maximum values for calculations
    static final long VAL_MAX = (long) (1e+10);
    static final long SUM_MAX = VAL_MAX * 3;

    // Structure to represent a range with start and end indices
    static class Range {
        int start;
        int end;

        Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    // Function to find the lower bound index of a key in a sorted array
    static int lowerBound(long[] arr, Range r, long key) {
        int low = r.start;
        int high = r.end;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public static void main(String[] args) {
        // Variables to hold input values and rank
        int[] input = new int[4];
        getInt4(input);
        int x = input[0], y = input[1], z = input[2], rank = input[3];

        // Arrays to hold input values
        long[] xrr = fgetArray(x);
        long[] yrr = fgetArray(y);
        long[] zrr = fgetArray(z);

        // Initialize min and max sums
        long minSum = VAL_MAX + 1;
        long maxSum = 0;

        // Calculate minimum and maximum values from zrr
        for (long value : zrr) {
            minSum = Math.min(minSum, value);
            maxSum = Math.max(maxSum, value);
        }

        // Create an array to hold the sums of pairs from xrr and yrr
        long[] pair = new long[NUM2_MAX];
        int idx = 0;

        // Calculate all possible sums of pairs from xrr and yrr
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }

        // Sort the pair array in ascending order
        Arrays.sort(pair);

        // Update min and max sums with the smallest and largest pair sums
        minSum += pair[0];
        maxSum += pair[idx - 1];

        // Arrays for caching and counting
        int[] cache = new int[NUM_MAX];
        int[] cntMap = new int[NUM_MAX];
        long[] ans = new long[RANK_MAX];

        // Calculate the size of the combined array
        int size = x * y * z;
        long prev = minSum;
        int r;

        // Iterate to find the rank-th largest sum
        for (r = rank; r >= 1; r--) {
            long low = prev - 1;
            long high = maxSum + 1;

            // Binary search to find the appropriate sum
            while (low < high) {
                long mid = (low + high) / 2;
                int cnt = 0;

                // Count how many sums are less than or equal to mid
                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    Range rng = new Range(cache[i] - 1, idx);
                    int tmp = lowerBound(pair, rng, mid - pivot);
                    cntMap[i] = tmp;
                    cnt += tmp;
                }

                // Adjust the search range based on the count
                if (cnt <= size - r) {
                    System.arraycopy(cntMap, 0, cache, 0, z);
                    low = mid;
                } else {
                    high = mid;
                }
            }

            // Store the found sum in the answer array
            ans[r - 1] = low;
            if (low == maxSum) break; // Stop if we reach the maximum sum
            prev = low; // Update previous sum for the next iteration
        }

        // Print the results for each rank
        for (int i = 0; i < rank; i++) {
            System.out.println(ans[i] == 0 ? maxSum : ans[i]);
        }
    }
}
