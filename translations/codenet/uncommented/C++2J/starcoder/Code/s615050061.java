import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = new char[n + 1];
		s[0] ='';
		sc.next();
		for (int i = 1; i <= n; ++i)
			s[i] = sc.next().charAt(0);
		long[] f = new long[n + 1];
		int[] g = new int[n + 1];
		f[0] = 0;
		g[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '+' || s[i] == '-')
				f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * Math.pow(13131, g[i] = g[i - 1]);
			else
				f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<'? -1 : 1);
		}
		Map<Long, Long> map = new TreeMap<Long, Long>();
		long cnt = 0;
		for (int i = n; i; --i)
			map.put(f[i], map.getOrDefault(f[i], 0l) + 1);
		for (int i = n; i; --i)
			cnt += map.getOrDefault(f[n] * Math.pow(13131, g[i - 1]) + f[i - 1], 0l);
		System.out.println(cnt);
	}
}

