// AOJ 2275: Fox Number
// 2017.12.11 bal4u@uu

import java.util.*;
import java.io.*;

public class Main {
	static int MAX = 707106;		// sqrt(10^12/2)
	static char tbl[] = new char[MAX+1];
	static int sz;
	static int prime[] = new int[57100];	// prime[146] = 853, prime[147] = 857
	static int sqp[] = new int[147];		// squre of prime: sqp[i] = prime[i] * prime[i]
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// 2^40 = 1099511627776 >= 10^12

	public static void sieve() {
		int i, j, k;

		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1;
		}
		for (sz = 146, i = 853; i <= MAX; i += 2) if (tbl[i] == 0) prime[sz++] = i;
	}

	public static int bsch(int x) {
		int m, l = 0, r = sz;

		while (l < r) {
			m = (l + r) >> 1;
			if (prime[m] == x) return m;
			if (prime[m] < x) l = m + 1; else r = m;
		}
		return l-1;
	}

	public static void main(String[] args) throws Exception {
		int i, k, p, ans;
		long A, B, a, b, j, ll, rr;

		sieve();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		A = Long.parseLong(line[0]);
		B = Long.parseLong(line[1]);
		a = A-B, b = A+B;
		if (b <= 1) { System.out.println("0"); return; }
		if (a <= 1) a = 2;

		sz = bsch((int)Math.sqrt((double)(b >> 1)));

		Arrays.fill(idx, 1);
		for (i = 0; i <= sz; i++) {
			p = prime[i];
			for (k = 1, j = p; j <= b; j *= p) pp[k++] = j;
			while (--k) {
				j = pp[k], ll = j*(1+(a-1)/j), rr = j*(b/j);
				for (; ll <= rr; ll += j) {
					int x = (int)(ll-a);
					if (idx[x] == 0 || base[x] == p) continue;
					if (idx[x] < k) idx[x] = 0;
					else base[x] = p, idx[x] = k;
				}
			}
		}

		ans = 0, i = (int)(b-a+1); while (i-- > 0) if (idx[i] > 0) ans++;
		System.out.println(ans);
	}
}

