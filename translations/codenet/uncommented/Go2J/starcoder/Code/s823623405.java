import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] as = new int[n];
		Map<Integer, Integer> ps = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			as[i] = sc.nextInt();

			Map<Integer, Integer> ns = primeFactorize(as[i]);
			for (int k : ns.keySet()) {
				ps.put(k, Math.max(ps.getOrDefault(k, 0), ns.get(k)));
			}
		}

		int x = 1;
		for (int k : ps.keySet()) {
			for (int i = 1; i <= ps.get(k); i++) {
				x = (x * k) % mod;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans + div(x, as[i])) % mod;
		}
		System.out.println(ans);
	}

	public static Map<Integer, Integer> primeFactorize(int n) {
		Map<Integer, Integer> res = new HashMap<Integer, Integer>();
		for (int i = 2; i * i <= n; i++) {
			for (int j = 0; n % i == 0; n /= i, j++) {
				res.put(i, Math.max(res.getOrDefault(i, 0), j));
			}
		}
		if (n!= 1) {
			res.put(n, res.getOrDefault(n, 0) + 1);
		}
		return res;
	}

	public static final int mod = 1000000007;

	public static int pow(int n, int k) {
		if (k == 0) {
			return 1;
		} else if (k % 2 == 1) {
			return pow(n, k - 1) * n % mod;
		} else {
			int t = pow(n, k / 2);
			return t * t % mod;
		}
	}

	public static int add(int a, int b) {
		return (a + b) % mod;
	}

	public static int sub(int a, int b) {
		return (a + mod - b) % mod;
	}

	public static int mul(int a, int b) {
		return a % mod * b % mod % mod;
	}

	public static int div(int a, int b) {
		return mul(a, pow(b, mod - 2));
	}
}

