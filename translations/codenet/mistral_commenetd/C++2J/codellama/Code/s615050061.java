
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();
		long[] f = new long[n + 1];
		int[] g = new int[n + 1];
		Map<Long, Long> map = new HashMap<>();
		long cnt = 0;

		f[0] = 0;
		g[0] = 0;

		for (int i = 1; i <= n; ++i) {
			if (s[i] == '+' || s[i] == '-')
				f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * (long) Math.pow(13131, g[i] = g[i - 1]);
			else
				f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1);
		}

		for (int i = n; i; --i) {
			map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
			cnt += map.getOrDefault(f[n] * (long) Math.pow(13131, g[i - 1]) + f[i - 1], 0L);
		}

		System.out.println(cnt);
	}
}

