import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int MX = 10000;
        int[] sieve = new int[MX];
        List<Integer> primes = new ArrayList<>();

        for (int i = 2; i < MX; i++) {
            if (sieve[i] != 0) {
                continue;
            }
            primes.add(i);
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i;
            }
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            ans++;
            for (int j = 0; j < primes.size(); j++) {
                if (x > primes.get(j) && x % primes.get(j) == 0) {
                    ans--;
                    break;
                }
            }
        }
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
