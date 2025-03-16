public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
        long minSum = Long.MAX_VALUE + 1;
        long maxSum = 0;
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
        java.util.Arrays.sort(pair, 0, idx);
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
                    Range rng = new Range(cache[i] - 1, idx);
                    int tmp = lowerBound(pair, rng, mid - pivot);
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
    }

    static class Range {
        int start;
        int end;

        Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

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
}
