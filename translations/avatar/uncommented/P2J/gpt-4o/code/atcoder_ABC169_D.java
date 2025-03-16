import java.util.*;
import java.io.*;

public class Main {
    static final long INF = 999999999999999999L;
    static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        if (n == 1) {
            System.out.println(0);
            return;
        }

        List<Integer> fac_ = primeFactorize(n);
        Map<Integer, Integer> fac = new HashMap<>();
        for (int p : fac_) {
            fac.put(p, fac.getOrDefault(p, 0) + 1);
        }

        long ans = 0;
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
        System.out.println(ans);
    }

    public static List<Integer> primeFactorize(int n) {
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
//<END-OF-CODE>
