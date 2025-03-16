
import java.util.Scanner;

public class s803744887{
    public static void main(String[] args) {
        final int MX = 10000;
        int[] sieve = new int[MX];
        int[] primes = new int[MX];
        int p = 0;
        for (int i = 2; i < MX; i++) {
            if (sieve[i]!= 0) {
                continue;
            }
            primes[p++] = i;
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
            for (int j = 0; j < p; j++) {
                if (x > primes[j] && x % primes[j] == 0) {
                    ans--;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
