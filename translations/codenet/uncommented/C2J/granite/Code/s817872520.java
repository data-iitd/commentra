
// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s817872520{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int w = Integer.parseInt(br.readLine());
		String[] s = br.readLine().split(" ");
		int[] a = new int[w+1];
		int[] b = new int[w+1];
		int ans = 0;
		int f = 0;
		int close = 0;
		for (int i = 1; i <= w; i++) {
			a[i] = Integer.parseInt(s[i-1]);
			if (a[i] == 0) {
				f |= 1;
			} else if (a[i] < 0) {
				f |= 2;
			} else {
				ans += a[i];
			}
		}
		if (ans == 0 || (f & 1) == 0) {
			System.out.println(0);
			return;
		}
		if ((f & 2) == 0) {
			System.out.println(ans);
			return;
		}
		close = 0;
		f = 0;
		for (int i = 1; i <= w; i++) {
			if (a[i] == 0) {
				close = 100000000;
				f = -1;
			} else if (a[i] < 0) {
				if (f < 0 || close - (i-f) > -a[i]) {
					close = -a[i];
					f = i;
				}
			} else {
				if (f < 0) {
					b[i] = 100000000;
				} else {
					int k = close - (i-f);
					if (k < 0) k = 0;
					b[i] = k;
				}
			}
		}
		close = 0;
		f = w;
		for (int i = w; i >= 1; i--) {
			if (a[i] == 0) {
				close = 100000000;
				f = -1;
			} else if (a[i] < 0) {
				if (f < 0 || close - (f-i) > -a[i]) {
					close = -a[i];
					f = i;
				}
			} else {
				if (f < 0) {
					b[i] = 100000000;
				} else {
					int k = close - (f-i);
					if (k < 0) k = 0;
					if (k > b[i]) b[i] = k;
				}
			}
		}
		for (int i = 1; i <= w; i++) {
			if (a[i] > 0) {
				if (b[i] > a[i]) ans += a[i];
				else ans += b[i];
			}
		}
		System.out.println(ans);
	}
}

