
import java.util.*;
import java.io.*;

class s327468529 {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		int q = sc.nextInt();
		long va = sc.nextLong();
		long vb = sc.nextLong();
		long vc = sc.nextLong();
		long vd = sc.nextLong();
		long ve = sc.nextLong();
		long vf = sc.nextLong();
		String ch = sc.next();
		String dh = sc.next();
		int i, j;

		// for (i = 0; i < h; i++) {
		// 	for (j = 0; j < w; j++) {
		// 		x[i][j] = (table[i][j] - 1) / w;
		// 	}
		// }

		long result = 1;
		for (i = 0; i < n * 3; i++) {
			long v;
			switch (s[i]) {
			case 'R':
				v = 0;
				break;
			case 'G':
				v = 1;
				break;
			case 'B':
				v = 2;
				break;
			}
			// printf("%llu %llu %llu\n", cnt[0], cnt[1], cnt[2]);

			if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
				// result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
				result *= pcnt;
				pcnt--;
				result %= FOD;
				cnt[(v + 1) % 3]--;
				cnt[(v + 2) % 3]--;
			} else {

				if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
					// printf("*%llu\n", (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]);
					result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
					result %= FOD;
					pcnt++;
					// printf("pcnt: %llu\n", pcnt);
				}

				cnt[v]++;
			}
			// printf("%llu\n", result);
		}

		for (i = 1; i <= n; i++) {
			result = (result * i) % FOD;
		}

		System.out.println(result);
		// printf("%.15f\n", dresult);
		// puts(s);

		return 0;

		success:
		// puts("YES");
		// printf("%llu\n", result);
		return 0;

		fail:
		// puts("NO");
		// puts("0");
		// puts("First");
		return 1;
	}
}