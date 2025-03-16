import java.util.*;
import java.io.*;

public class Main {
    static final long INF = 999999999999999999L;  // Constant for infinity
    static final int MOD = 1000000007;  // Constant for a large prime number

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());  // Read the integer n
        if (n == 1) {
            System.out.println(0);  // If n is 1, print 0 and exit
            return;
        }

        List<Integer> fac_ = primeFactorize(n);  // Get the prime factorization of n
        Map<Integer, Integer> fac = new HashMap<>();  // Count the occurrences of each prime factor
        for (int p : fac_) {
            fac.put(p, fac.getOrDefault(p, 0) + 1);
        }

        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : fac.entrySet()) {
            int x = entry.getValue();
            for (int i = 1; i < 99999999; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        System.out.println(ans);  // Print the final answer
    }

    private static List<Integer> primeFactorize(int n) {
        List<Integer> factors = new ArrayList<>();
        while (n % 2 == 0) {
            factors.add(2);
            n /= 2;
        }
        for (int f = 3; f * f <= n; f += 2) {
            while (n % f == 0) {
                factors.add(f);
                n /= f;
            }
        }
        if (n != 1) {
            factors.add(n);
        }
        return factors;
    }
}

// <END-OF-CODE>
