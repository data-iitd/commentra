
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		int n, q;
		n = sc.nextInt();
		q = sc.nextInt();

		int[] C = new int[n];
		for (int i = 0; i < n; i++) {
			C[i] = sc.nextInt();
		}

		Query[] Q = new Query[q];
		for (int i = 0; i < q; i++) {
			int l, r;
			l = sc.nextInt();
			r = sc.nextInt();
			Query query = new Query(i, l, r);
			Q[i] = query;
		}

		Arrays.sort(Q, new Comparator<Query>() {
			@Override
			public int compare(Query o1, Query o2) {
				if (o1.r < o2.r) {
					return -1;
				} else if (o1.r > o2.r) {
					return 1;
				} else {
					return 0;
				}
			}
		});

		int[] P = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			P[i] = -1;
		}

		FenwickTree ft = new FenwickTree(n + 1);

		int k = 0;
		for (Query query : Q) {
			for (k = query.l - 1; k < query.r; k++) {
				if (P[C[k]]!= -1) {
					ft.add(P[C[k]] + 1, -1);
				}
				P[C[k]] = k;
				ft.add(k + 1, 1);
			}

			System.out.println(ft.sum(query.r) - ft.sum(query.l - 1));
		}
	}
}

class FenwickTree {
	int[] dat;
	int n;
	int minPow2;

	public FenwickTree(int n) {
		this.n = n;
		dat = new int[n + 1];
		minPow2 = 1;
		while ((minPow2 << 1) <= n) {
			minPow2 <<= 1;
		}
	}

	public int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += dat[i];
			i -= i & -i;
		}
		return s;
	}

	public void add(int i, int x) {
		while (i <= n) {
			dat[i] += x;
			i += i & -i;
		}
	}

	public int lowerBound(int w) {
		if (w <= 0) {
			return 0;
		}

		int x = 0;
		for (int k = minPow2; k > 0; k >>= 1) {
			if (x + k <= n && dat[x + k] < w) {
				w -= dat[x + k];
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

