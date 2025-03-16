import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static final int NUM_MAX = 1000;
    private static final int NUM2_MAX = NUM_MAX * NUM_MAX;
    private static final int RANK_MAX = 3000;
    private static final long VAL_MAX = (long) (1e+10);
    private static final long SUM_MAX = VAL_MAX * 3;

    private static void getInt4(Scanner scanner, int[] arr) {
        for (int i = 0; i < 4; i++) {
            arr[i] = scanner.nextInt();
        }
    }

    private static void fgetArray(Scanner scanner, long[] arr, int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextLong();
        }
    }

    private static int asc(Long a1, Long a2) {
        return Long.compare(a1, a2);
    }

    private static int desc(Long a1, Long a2) {
        return Long.compare(a2, a1);
    }

    private static int lowerBound(long[] arr, int start, int end, long key) {
        int low = start;
        int high = end;
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
        int[] inputs = new int[4];
        getInt4(scanner, inputs);
        int x = inputs[0], y = inputs[1], z = inputs[2], rank = inputs[3];

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
        }
        for (int i = 0; i < z; i++) {
            maxSum = Math.max(maxSum, zrr[i]);
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
                int cnt = 0;
                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    int tmp = lowerBound(pair, cache[i] - 1, idx, mid - pivot);
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
