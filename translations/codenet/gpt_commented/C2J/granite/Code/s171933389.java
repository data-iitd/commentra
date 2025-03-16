
import java.util.Arrays;
import java.util.Scanner;

public class s171933389{
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
        long minSum = Long.MAX_VALUE;
        long maxSum = Long.MIN_VALUE;
        for (int i = 0; i < z; i++) {
            minSum = Math.min(minSum, zrr[i]);
            maxSum = Math.max(maxSum, zrr[i]);
        }
        long[] pair = new long[x * y];
        int index = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pair[index++] = xrr[i] + yrr[j];
            }
        }
        Arrays.sort(pair);
        minSum += pair[0];
        maxSum += pair[pair.length - 1];
        int[] cache = new int[z];
        int[] cntMap = new int[z];
        long[] ans = new long[rank];
        long prev = minSum;
        int r;
        for (r = rank; r >= 1; r--) {
            long low = prev - 1;
            long high = maxSum + 1;
            while (low + 1 < high) {
                long mid = (low + high) / 2;
                int cnt = 0;
                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    int left = cache[i] - 1;
                    int right = pair.length - 1;
                    while (left < right) {
                        int mid2 = (left + right) / 2;
                        if (pair[mid2] <= mid - pivot) {
                            left = mid2 + 1;
                        } else {
                            right = mid2;
                        }
                    }
                    cntMap[i] = left;
                    cnt += left;
                }
                if (cnt <= x * y * z - r) {
                    System.arraycopy(cntMap, 0, cache, 0, z);
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans[r - 1] = low;
            if (low == maxSum) {
                break;
            }
            prev = low;
        }
        for (int i = 0; i < rank; i++) {
            System.out.println(ans[i] == 0? maxSum : ans[i]);
        }
    }
}

// Translate the above Java code to C and end with comment "