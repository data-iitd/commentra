import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Constants are defined for the maximum values of various quantities.
    private static final int NUM_MAX = 1000;
    private static final long VAL_MAX = (long) (1e+10);
    private static final long SUM_MAX = VAL_MAX * 3;
    private static final int RANK_MAX = 3000;

    // A structure is defined to represent a range of indices.
    static class Range {
        int start;
        int end;

        Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    // This function finds the lower bound of a key in a sorted array within a given range.
    private static int lowerBound(long[] arr, Range r, long key) {
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
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int rank = scanner.nextInt();

        long[] xrr = new long[x];
        long[] yrr = new long[y];
        long[] zrr = new long[z];

        for (int i = 0; i < x; i++) {
            xrr[i] = scanner.nextLong();
        }
        for (int i = 0; i < y; i++) {
            yrr[i] = scanner.nextLong();
        }
        for (int i = 0; i < z; i++) {
            zrr[i] = scanner.nextLong();
        }

        long minSum = VAL_MAX + 1;
        long maxSum = 0;

        for (int i = 0; i < z; i++) {
            minSum = Math.min(minSum, zrr[i]);
        }
        for (int i = 0; i < z; i++) {
            maxSum = Math.max(maxSum, zrr[i]);
        }

        long[] pair = new long[NUM_MAX * NUM_MAX];
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
                int cnt = 0;
                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    Range range = new Range(cache[i] - 1, idx);
                    int tmp = lowerBound(pair, range, mid - pivot);
                    cntMap[i] = tmp;
                    cnt += tmp;
                }
                if (cnt <= size - r) {
                    System.arraycopy(cntMap, 0, cache, 0, z);
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
}
// <END-OF-CODE>
