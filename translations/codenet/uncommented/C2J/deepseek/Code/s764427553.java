public class PrimeCounter {
    public static void main(String[] args) {
        final int MAX_V = 999999;
        boolean[] prime = new boolean[MAX_V + 1];
        int i, k, n;
        for (i = 2; i <= MAX_V; i++) {
            prime[i] = true;
        }
        for (i = 2; i * i <= MAX_V; i++) {
            if (prime[i]) {
                for (k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = false;
                }
            }
        }
        prime[0] = false;
        prime[1] = false;
        int count = 0;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            count++;
            n = scanner.nextInt();
            int cnt = 0;
            for (i = n; i > 0; i--) {
                if (prime[i]) {
                    cnt++;
                }
            }
            System.out.println(cnt);
            if (count == 30) break;
        }
    }
}
