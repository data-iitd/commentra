import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] primes = new int[10000];
		int[] sieve = new int[10000];
		Arrays.fill(sieve, 0);
		for (int i = 2; i < 10000; i++) {
			if (sieve[i]!= 0) {
				continue;
			}
			primes[primes.length] = i;
			for (int j = i + i; j < 10000; j += i) {
				sieve[j] = i;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			ans++;
			for (int j = 0; j < primes.length; j++) {
				if (x > primes[j] && x % primes[j] == 0) {
					ans--;
					break;
				}
			}
		}
		System.out.println(ans);
	}
}

