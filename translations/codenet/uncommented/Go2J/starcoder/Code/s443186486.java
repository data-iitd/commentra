import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}

		int[] s = new int[n + 1];
		for (int i = 0; i < n; i++) {
			s[i + 1] = s[i] + a[i];
		}

		Arrays.sort(s);

		int ans = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == s[i + 1]) {
				count++;
			} else if (count > 0) {
				ans += combi(count + 1, 2);
				count = 0;
			}
		}
		if (count > 0) {
			ans += combi(count + 1, 2);
		}

		System.out.println(ans);
	}

	public static int combi(int n, int r) {
		int c = 1;
		for (int i = 1; i <= r; i++) {
			c = c * (n - i + 1) / i;
		}
		return c;
	}
}

