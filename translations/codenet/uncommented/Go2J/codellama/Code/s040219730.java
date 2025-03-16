
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	// <START-OF-CODE>
	private static class Query {
		int idx;
		int l;
		int r;

		public Query(int idx, int l, int r) {
			this.idx = idx;
			this.l = l;
			this.r = r;
		}
	}

	private static int n;
	private static int q;
	private static int[] C;
	private static List<Query> Q = new ArrayList<>();

	private static int[] P = new int[500000 + 50];
	private static int[] Answers = new int[500000 + 50];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		C = new int[n];
		for (int i = 0; i < n; i++) {
			C[i] = Integer.parseInt(br.readLine());
		}

		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			Query query = new Query(i, l, r);
			Q.add(query);
		}

		for (int i = 1; i <= n; i++) {
			P[i] = -1;
		}

		int k = 0;
		for (Query query : Q) {
			while (k < query.r) {
				if (P[C[k]] != -1) {
					P[C[k]] = -1;
				}
				P[C[k]] = k;
				k++;
			}
			Answers[query.idx] = getSum(query.r) - getSum(query.l - 1);
		}

		for (int i = 0; i < q; i++) {
			System.out.println(Answers[i]);
		}
	}

	private static int getSum(int r) {
		int sum = 0;
		while (r > 0) {
			sum += P[r];
			r -= r & (-r);
		}
		return sum;
	}
	// 