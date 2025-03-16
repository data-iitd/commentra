import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }

        List<Integer> primeFactors = primeFactorize(n);
        Map<Integer, Integer> factorCount = new HashMap<>();
        for (int factor : primeFactors) {
            factorCount.put(factor, factorCount.getOrDefault(factor, 0) + 1);
        }

        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : factorCount.entrySet()) {
            int e = entry.getValue();
            for (int i = 1; ; i++) {
                if (e >= i) {
                    e -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        System.out.println(ans);
    }

    private static List<Integer> primeFactorize(int n) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }
}
