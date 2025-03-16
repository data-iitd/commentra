
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[][] dpx, dpy;
	static int x, y;
	static List<Integer> evens, odds;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int[][] dp = new int[N + 1][M + 1];
		dpx = new int[N + 1][M + 1];
		dpy = new int[N + 1][M + 1];
		evens = new ArrayList<>();
		odds = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				dp[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dp[i][j] == 0) {
					continue;
				}
				if (i + dp[i][j] <= N && j + dp[i][j] <= M) {
					dpx[i + dp[i][j]][j + dp[i][j]] = 1;
				}
				if (i - dp[i][j] >= 0 && j - dp[i][j] >= 0) {
					dpx[i - dp[i][j]][j - dp[i][j]] = 1;
				}
				if (i + dp[i][j] <= N && j - dp[i][j] >= 0) {
					dpy[i + dp[i][j]][j - dp[i][j]] = 1;
				}
				if (i - dp[i][j] >= 0 && j + dp[i][j] <= M) {
					dpy[i - dp[i][j]][j + dp[i][j]] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dpx[i][j] == 1 && dpy[i][j] == 1) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}

