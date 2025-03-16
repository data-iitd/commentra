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
        int ans = 0;
        for (int p : primeFactorize(n)) {
            int x = p;
            for (int i = 1; i < 100000000; i++) {
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

    public static List<Integer> primeFactorize(int n) {
        List<Integer> ans = new ArrayList<>();
        while (n % 2 == 0) {
            ans.add(2);
            n /= 2;
        }
        int f = 3;
        while (f * f <= n) {
            if (n % f == 0) {
                ans.add(f);
                n /= f;
            } else {
                f += 2;
            }
        }
        if (n!= 1) {
            ans.add(n);
        }
        return ans;
    }
}

