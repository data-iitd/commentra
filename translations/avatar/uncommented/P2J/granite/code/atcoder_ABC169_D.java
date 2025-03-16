
import java.util.*;
import java.io.*;

class atcoder_ABC169_D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if (N == 1) {
            System.out.println(0);
            return;
        }
        List<Integer> prime_factors = new ArrayList<>();
        int n = N;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                prime_factors.add(i);
                n /= i;
            }
        }
        if (n!= 1) {
            prime_factors.add(n);
        }
        Map<Integer, Integer> prime_count = new HashMap<>();
        for (int p : prime_factors) {
            prime_count.put(p, prime_count.getOrDefault(p, 0) + 1);
        }
        int ans = 0;
        for (int p : prime_count.keySet()) {
            int e = prime_count.get(p);
            for (int i = 1; i <= e; i++) {
                ans += e / i;
            }
        }
        System.out.println(ans);
    }
}

Translate the above Python code to C++ and end with comment "