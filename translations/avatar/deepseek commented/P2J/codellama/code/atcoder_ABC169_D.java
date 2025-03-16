
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }

        int[] fac_ = primeFactorize(n);
        Map<Integer, Integer> fac = new HashMap<>();
        for (int i = 0; i < fac_.length; i++) {
            if (fac.containsKey(fac_[i])) {
                fac.put(fac_[i], fac.get(fac_[i]) + 1);
            } else {
                fac.put(fac_[i], 1);
            }
        }

        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : fac.entrySet()) {
            int p = entry.getKey();
            int e = entry.getValue();
            int x = e;
            for (int i = 1; i < 99999999; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        System.out.println(ans);
    }

    public static int[] primeFactorize(int n) {
        List<Integer> a = new ArrayList<>();
        while (n % 2 == 0) {
            a.add(2);
            n /= 2;
        }
        int f = 3;
        while (f * f <= n) {
            if (n % f == 0) {
                a.add(f);
                n /= f;
            } else {
                f += 2;
            }
        }
        if (n != 1) {
            a.add(n);
        }
        int[] fac = new int[a.size()];
        for (int i = 0; i < a.size(); i++) {
            fac[i] = a.get(i);
        }
        return fac;
    }
}

