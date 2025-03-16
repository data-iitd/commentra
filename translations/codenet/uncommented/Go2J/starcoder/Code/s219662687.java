package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	class SegmentTree {
		int n;
		int[] a;
		int[] lazy;

		public SegmentTree(int n) {
			this.n = n;
			a = new int[n * 4];
			lazy = new int[n * 4];
		}

		public void build(int[] a) {
			build(a, 0, 0, n);
		}

		private void build(int[] a, int i, int l, int r) {
			if (l == r) {
				this.a[i] = a[l];
				return;
			}

			int m = (l + r) / 2;
			build(a, i*2+1, l, m);
			build(a, i*2+2, m, r);
			this.a[i] = Math.min(this.a[i*2+1], this.a[i*2+2]);
		}

		public int query(int l, int r) {
			return query(0, 0, n, l, r);
		}

		private int query(int i, int l, int r, int ql, int qr) {
			if (l >= ql && r <= qr) {
				return a[i];
			}

			if (lazy[i]!= 0) {
				a[i*2+1] += lazy[i];
				a[i*2+2] += lazy[i];
				lazy[i*2+1] += lazy[i];
				lazy[i*2+2] += lazy[i];
				lazy[i] = 0;
			}

			int m = (l + r) / 2;
			if (qr <= m) {
				return query(i*2+1, l, m, ql, qr);
			} else if (ql >= m) {
				return query(i*2+2, m, r, ql, qr);
			} else {
				return Math.min(query(i*2+1, l, m, ql, qr), query(i*2+2, m, r, ql, qr));
			}
		}

		public void update(int i, int v) {
			update(0, 0, n, i, v);
		}

		private void update(int i, int l, int r, int p, int v) {
			if (l == r) {
				a[i] = v;
				return;
			}

			int m = (l + r) / 2;
			if (p < m) {
				update(i*2+1, l, m, p, v);
			} else {
				update(i*2+2, m, r, p, v);
			}

			a[i] = Math.min(a[i*2+1], a[i*2+2]);
		}
	}

	class LazySegmentTree {
		int n;
		int[] a;
		int[] lazy;

		public LazySegmentTree(int n) {
			this.n = n;
			a = new int[n * 4];
			lazy = new int[n * 4];
		}

		public void build(int[] a) {
			build(a, 0, 0, n);
		}

		private void build(int[] a, int i, int l, int r) {
			if (l == r) {
				this.a[i] = a[l];
				return;
			}

			int m = (l + r) / 2;
			build(a, i*2+1, l, m);
			build(a, i*2+2, m, r);
			this.a[i] = Math.min(this.a[i*2+1], this.a[i*2+2]);
		}

		public int query(int l, int r) {
			return query(0, 0, n, l, r);
		}

		private int query(int i, int l, int r, int ql, int qr) {
			if (l >= ql && r <= qr) {
				return a[i];
			}

			if (lazy[i]!= 0) {
				a[i*2+1] += lazy[i];
				a[i*2+2] += lazy[i];
				lazy[i*2+1] += lazy[i];
				lazy[i*2+2] += lazy[i];
				lazy[i] = 0;
			}

			int m = (l + r) / 2;
			if (qr <= m) {
				return query(i*2+1, l, m, ql, qr);
			} else if (ql >= m) {
				return query(i*2+2, m, r, ql, qr);
			} else {
				return Math.min(query(i*2+1, l, m, ql, qr), query(i*2+2, m, r, ql, qr));
			}
		}

		public void update(int i, int v) {
			update(0, 0, n, i, v);
		}

		private void update(int i, int l, int r, int p, int v) {
			if (l == r) {
				a[i] = v;
				return;
			}

			int m = (l + r) / 2;
			if (p < m) {
				update(i*2+1, l, m, p, v);
			} else {
				update(i*2+2, m, r, p, v);
			}

			a[i] = Math.min(a[i*2+1], a[i*2+2]);
		}
	}

	void run() {
		int A = nextInt();
		int B = nextInt();
		int Q = nextInt();
		int[] s = new int[A+2];
		int[] t = new int[B+2];
		s[0] = -1000000000;
		s[A+1] = 1000000000;
		for (int i = 1; i <= A; i++) {
			s[i] = nextInt();
		}

		t[0] = -1000000000;
		t[B+1] = 1000000000;
		for (int i = 1; i <= B; i++) {
			t[i] = nextInt();
		}

		SegmentTree st = new SegmentTree(A+2);
		st.build(s);
		LazySegmentTree lst = new LazySegmentTree(B+2);
		lst.build(t);

		for (int i = 0; i < Q; i++) {
			int x = nextInt();
			int b = Arrays.binarySearch(s, x);
			int d = Arrays.binarySearch(t, x);
			int res = 1000000000;
			for (int S : new int[]{s[b-1], s[b]}) {
				for (int T : new int[]{t[d-1], t[d]}) {
					int d1 = Math.abs(S-x) + Math.abs(T-S);
					int d2 = Math.abs(T-x) + Math.abs(S-T);
					res = Math.min(res, Math.min(d1, d2));
				}
			}

			System.out.println(res);
		}
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextString());
	}

	static String nextString() throws IOException {
		byte[] s = new byte[1024];
		int len = 0;
		int b;

		while ((b = System.in.read())!= -1) {
			if (b == 10) {
				break;
			}

			s[len++] = (byte) b;
		}

		return new String(s, 0, len);
	}
}

// END-OF-CODE

'''
