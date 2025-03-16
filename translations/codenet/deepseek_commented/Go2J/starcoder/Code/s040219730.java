
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		// br := bufio.NewReader(os.Stdin)
		// out := new PrintWriter(os.Stdout, true)
		// defer out.close()

		int n, q;
		n = ReadInt();
		q = ReadInt();
		int[] C = new int[n];
		for (int i = 0; i < n; i++) {
			C[i] = ReadInt();
		}

		Query[] Q = new Query[q];
		for (int i = 0; i < q; i++) {
			int l, r;
			l = ReadInt();
			r = ReadInt();
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

		FenwickTree ft = new FenwickTree(500000 + 50);
		int k = 0;
		for (Query query : Q) {
			while (k < query.r) {
				if (P[C[k]]!= -1) {
					ft.add(P[C[k]] + 1, -1);
				}
				P[C[k]] = k;
				ft.add(k + 1, 1);
				k++;
			}
			int ans = ft.sum(query.r) - ft.sum(query.l - 1);
			out.println(ans);
		}
	}

	static class Query {
		int idx, l, r;

		public Query(int idx, int l, int r) {
			this.idx = idx;
			this.l = l;
			this.r = r;
		}
	}

	static class FenwickTree {
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

	static boolean DEBUG = false;

	static void debug(Object...os) {
		if (!DEBUG)
			return;
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}

	static int[] ReadInts(int N, BufferedReader br) throws Exception {
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = ReadInt(br);
		}
		return A;
	}

	static int ReadInt(BufferedReader br) throws Exception {
		int ret = Integer.parseInt(br.readLine());
		if (DEBUG)
			System.err.printf("ReadInt() i = %d; ret = %d\n", br.tell(), ret);
		return ret;
	}

	static int[] ReadInts(int N) throws Exception {
		return ReadInts(N, new BufferedReader(new InputStreamReader(System.in)));
	}

	static int[] ReadInts(int N, String file) throws Exception {
		return ReadInts(N, new BufferedReader(new FileReader(file)));
	}

	static void WriteInts(int[] A, BufferedWriter bw) throws Exception {
		for (int i = 0; i < A.length; i++) {
			bw.write(String.format("%d ", A[i]));
		}
		bw.write("\n");
	}

	static void WriteInts(int[] A) throws Exception {
		WriteInts(A, new BufferedWriter(new OutputStreamWriter(System.out)));
	}

	static void WriteInts(int[] A, String file) throws Exception {
		WriteInts(A, new BufferedWriter(new FileWriter(file)));
	}

	static int[][] ReadIntMatrix(int N, int M, BufferedReader br) throws Exception {
		int[][] A = new int[N][M];
		for (int i = 0; i < N; i++) {
			A[i] = ReadInts(M, br);
		}
		return A;
	}

	static int[][] ReadIntMatrix(int N, int M) throws Exception {
		return ReadIntMatrix(N, M, new BufferedReader(new InputStreamReader(System.in)));
	}

	static int[][] ReadIntMatrix(int N, int M, String file) throws Exception {
		return ReadIntMatrix(N, M, new BufferedReader(new FileReader(file)));
	}

	static void WriteIntMatrix(int[][] A, BufferedWriter bw) throws Exception {
		for (int i = 0; i < A.length; i++) {
			WriteInts(A[i], bw);
		}
	}

	static void WriteIntMatrix(int[][] A) throws Exception {
		WriteIntMatrix(A, new BufferedWriter(new OutputStreamWriter(System.out)));
	}

	static void WriteIntMatrix(int[][] A, String file) throws Exception {
		WriteIntMatrix(A, new BufferedWriter(new FileWriter(file)));
	}
}

