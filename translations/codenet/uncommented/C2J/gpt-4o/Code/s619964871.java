import java.util.Scanner;

public class TheNumberOfInversionsFix {
    private static final long UNKO = (long) 1e12;

    private static long sort(long[] a, int left, int middle, int right) {
        long[] lArr = new long[middle - left + 1];
        long[] rArr = new long[right - middle + 1];
        long cnt = 0;

        for (int i = 0; i < middle - left; i++) {
            lArr[i] = a[i + left];
        }
        for (int i = 0; i < right - middle; i++) {
            rArr[i] = a[i + middle];
        }
        lArr[middle - left] = UNKO;
        rArr[right - middle] = UNKO;

        int l = 0, r = 0;
        for (int i = 0; i < right - left; i++) {
            if (lArr[l] <= rArr[r]) {
                a[left + i] = lArr[l++];
            } else {
                a[left + i] = rArr[r++];
                cnt += middle - left - l;
            }
        }
        return cnt;
    }

    private static long merge(long[] a, int left, int right) {
        if (left + 1 < right) {
            int middle = (left + right) / 2;
            long x1 = merge(a, left, middle);
            long x2 = merge(a, middle, right);
            long x3 = sort(a, left, middle, right);
            return x1 + x2 + x3;
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        System.out.println(merge(a, 0, n));
        scanner.close();
    }
}

// <END-OF-CODE>
