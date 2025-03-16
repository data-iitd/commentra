import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] C = new int[n];
		for (int i = 0; i < n; i++) {
			C[i] = sc.nextInt();
		}

		Query[] Q = new Query[q];
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			Q[i] = new Query(i, l, r);
		}

		Arrays.sort(Q, (a, b) -> a.r - b.r);

		int[] P = new int[500000 + 50];
		Arrays.fill(P, -1);

		FenwickTree ft = new FenwickTree(500000 + 50);

		int k = 0;
		for (Query query : Q) {
			for (int i = k; i < query.r; i++) {
				if (P[C[i]]!= -1) {
					ft.add(P[C[i]] + 1, -1);
				}
				P[C[i]] = i;
				ft.add(i + 1, 1);
			}

			int ans = ft.sum(query.r) - ft.sum(query.l - 1);
			System.out.println(ans);
		}
	}
}

class FenwickTree {
	int[] dat;
	int n;
	int minPow2;

	public FenwickTree(int n) {
		this.dat = new int[n + 1];
		this.n = n;

		this.minPow2 = 1;
		while ((this.minPow2 << 1) <= n) {
			this.minPow2 <<= 1;
		}
	}

	public int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += this.dat[i];
			i -= i & (-i);
		}
		return s;
	}

	public void add(int i, int x) {
		while (i <= this.n) {
			this.dat[i] += x;
			i += i & (-i);
		}
	}

	public int lowerBound(int w) {
		if (w <= 0) {
			return 0;
		}

		int x = 0;
		for (int k = this.minPow2; k > 0; k >>= 1) {
			if (x + k <= this.n && this.dat[x + k] < w) {
				w -= this.dat[x + k];
				x += k;
			}
		}

		return x + 1;
	}
}

class Query {
	int idx, l, r;

	public Query(int idx, int l, int r) {
		this.idx = idx;
		this.l = l;
		this.r = r;
	}
}

