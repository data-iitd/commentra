
import java.util.*;
import java.io.*;

class s327468529 {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		int q = sc.nextInt();
		int va = sc.nextInt();
		int vb = sc.nextInt();
		int vc = sc.nextInt();
		int vd = sc.nextInt();
		int ve = sc.nextInt();
		int vf = sc.nextInt();
		int ch = sc.nextInt();
		int dh = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int[] d = new int[n];
		int[] e = new int[q];
		String[] s = new String[n];
		String[] t = new String[n];
		String[] u = new String[n];
		int[][] xy = new int[q][2];
		int[][] tup = new int[q][3];
		int[][] table = new int[h][w];
		long[] gin = new long[n];
		int result = 0;
		int maybe = 0;
		int sum = 0;
		int item;
		int[] dpcell = new int[n];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				x[i][j] = (table[i][j] - 1) / w;
			}
		}
		result = 1;
		for (int i = 0; i < n * 3; i++) {
			int v;
			switch (s[i]) {
			case "R":
				v = 0;
				break;
			case "G":
				v = 1;
				break;
			case "B":
				v = 2;
				break;
			}
			if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
				result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
				pcnt++;
				cnt[(v + 1) % 3]--;
				cnt[(v + 2) % 3]--;
			} else {
				if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
					result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
					result %= FOD;
					pcnt++;
					// printf("pcnt: %llu\n", pcnt);
				}
				cnt[v]++;
			}
			// printf("%llu\n", result);
		}
		for (int i = 1; i <= n; i++) {
			result = (result * i) % FOD;
		}
		printf("%lld\n", result);
		// printf("%.15f\n", dresult);
		// puts(s);
		return 0;
	}
}