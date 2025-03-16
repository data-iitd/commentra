import java.util.Scanner;

public class PrimeCounter {
    public static void main(String[] args) {
        final int MAX_V = 999999;
        int[] prime = new int[MAX_V + 1];
        int i, k, n;

        for (i = 2; i <= MAX_V; i++) {
            prime[i] = 1;
        }

        for (i = 2; i * i <= MAX_V; i++) {
            if (prime[i] == 1) {
                for (k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = 0;
                }
            }
        }

        prime[0] = 0;
        prime[1] = 0;
        int count = 0;
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            count++;
            int cnt = 0;

            for (i = n; i > 0; i--) {
                if (prime[i] == 1) {
                    cnt++;
                }
            }

            System.out.println(cnt);
            if (count == 30) break;
        }

        scanner.close();
    }
}
// <END-OF-CODE>
