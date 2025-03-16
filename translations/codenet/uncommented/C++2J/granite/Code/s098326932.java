

import java.io.*;
import java.util.*;

public class s098326932{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        long n = 1;
        for (int i = 0; i < k; i++) {
            System.out.println(n);
            n = f(n + 1);
        }
    }

    static long f(long n) {
        int d = 0;
        long[] a = new long[20];
        while (n > 0) {
            a[d] = n % 10;
            n /= 10;
            d++;
        }
        double m = 1e18;
        long res = n;
        for (int i = 0; i <= d; i++) {
            long bunsi = 0;
            long bunbo = 9 * i;
            for (int j = d - 1; j >= 0; j--) {
                bunsi *= 10;
                if (j < i) bunsi += 9;
                else bunsi += a[j];

                if (j >= i) bunbo += a[j];

            }
            //cout << "bb" << bunsi <<  " " << bunbo << "  " << endl;
            double frac = (double) bunsi / (double) bunbo;
            if (frac < m) {
                m = frac;
                res = bunsi;
            }
        }
        return res;
    }
}

