import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int rank = scanner.nextInt();

        long[] xrr = new long[1000];
        long[] yrr = new long[1000];
        long[] zrr = new long[1000];
        for (int i = 0; i < x; i++) {
            xrr[i] = scanner.nextLong();
        }
        for (int i = 0; i < y; i++) {
            yrr[i] = scanner.nextLong();
        }
        for (int i = 0; i < z; i++) {
            zrr[i] = scanner.nextLong();
        }

        long minSum = Long.MAX_VALUE;
        long maxSum = Long.MIN_VALUE;
        for (int i = 0; i < z; i++) {
            minSum = Math.min(minSum, zrr[i]);
            maxSum = Math.max(maxSum, zrr[i]);
        }

        long[] pair = new long[1000000];
        int idx = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }
        Arrays.sort(pair, 0, idx);
        minSum += pair[0];
        maxSum += pair[idx - 1];

        int[] cache = new int[1000];
        int[] cntMap = new int[1000];
        long[] ans = new long[3000];
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
                    int start = cache[i] - 1;
                    int end = idx;
                    while (start + 1 < end) {
                        int midIdx = (start + end) / 2;
                        if (pair[midIdx] < mid - pivot) {
                            start = midIdx;
                        } else {
                            end = midIdx;
                        }
                    }
                    cntMap[i] = start + 1;
                    cnt += start + 1;
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
    }
}
