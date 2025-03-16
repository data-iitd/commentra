
import java.util.*;
import java.io.*;

class s462906333 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] v = Arrays.copyOf(a, n);
        int ans = Integer.MAX_VALUE;
        for (int k = 0; k < n; k++) {
            int kans = 0;
            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    v[i] = Math.min(v[i], a[n + i - k]);
                } else {
                    v[i] = Math.min(v[i], a[i - k]);
                }
                kans += v[i];
            }
            ans = Math.min(ans, kans + k * x);
        }
        System.out.println(ans);
    }
}

