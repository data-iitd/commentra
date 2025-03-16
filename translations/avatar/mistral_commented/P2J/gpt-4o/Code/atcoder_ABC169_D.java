import java.util.*;
import java.io.*;

public class Main {
    // Define constants
    static final long INF = 999999999999999999L;
    static final long MOD = 1000000007;

    // Custom input function
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        if (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // Function to prime factorize a number
    static List<Integer> primeFactorize(int n) {
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
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }

    public static void main(String[] args) throws IOException {
        // Get the number of test cases
        int n = nextInt();

        // Base case for the recursion
        if (n == 1) {
            System.out.println(0);
            return;
        }

        // Initialize variables
        List<Integer> fac_ = primeFactorize(n);
        Map<Integer, Integer> fac = new HashMap<>();
        for (int p : fac_) {
            fac.put(p, fac.getOrDefault(p, 0) + 1);
        }
        long ans = 0;

        // Calculate the answer
        for (Map.Entry<Integer, Integer> entry : fac.entrySet()) {
            int p = entry.getKey();
            int e = entry.getValue();
            int x = e;
            for (int i = 1; i < 1000000000; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
