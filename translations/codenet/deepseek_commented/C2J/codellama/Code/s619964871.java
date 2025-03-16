/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

import java.util.Scanner;

public class the_number_of_inversions_fix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        System.out.println(merge(a, 0, n));
    }

    public static long merge(long[] a, int left, int right) {
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

    public static long sort(long[] a, int left, int middle, int right) {
        long[] l_arr = new long[middle - left + 1];
        long[] r_arr = new long[right - middle + 1];
        long cnt = 0;
        for (int i = 0; i < middle - left; i++) {
            l_arr[i] = a[i + left];
        }
        for (int i = 0; i < right - middle; i++) {
            r_arr[i] = a[i + middle];
        }
        l_arr[middle - left] = unko;
        r_arr[right - middle] = unko;
        int l = 0, r = 0;
        for (int i = 0; i < right - left; i++) {
            if (l_arr[l] <= r_arr[r]) {
                a[left + i] = l_arr[l++];
            } else {
                a[left + i] = r_arr[r++];
                cnt += middle - left - l;
            }
        }
        return cnt;
    }

    public static final long unko = 1e12;
}

