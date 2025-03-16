
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int[] arr = new int[1000000000];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            int[] fac = primeFactorize(i);
            for (int j = 0; j < fac.length; j++) {
                int p = fac[j];
                int e = 0;
                while (i % p == 0) {
                    e++;
                    i /= p;
                }
                if (e == 0) continue;
                int x = e;
                for (int k = 1; k < 1000000000; k++) {
                    if (x >= k) {
                        x -= k;
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        System.out.println(ans);
    }

    public static int[] primeFactorize(int n) {
        int[] a = new int[1000000];
        int i = 0;
        while (n % 2 == 0) {
            a[i++] = 2;
            n /= 2;
        }
        int f = 3;
        while (f * f <= n) {
            if (n % f == 0) {
                a[i++] = f;
                n /= f;
            } else {
                f += 2;
            }
        }
        if (n!= 1) {
            a[i++] = n;
        }
        int[] ans = new int[i];
        for (int j = 0; j < i; j++) {
            ans[j] = a[j];
        }
        return ans;
    }
}

