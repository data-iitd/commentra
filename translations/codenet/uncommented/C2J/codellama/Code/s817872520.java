// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int w = Integer.parseInt(br.readLine());
		int[] a = new int[100002];
		int[] b = new int[100002];
		int ans = 0, f = 0, close = 0;
		String[] s = br.readLine().split(" ");
		for (int i = 1; i <= w; i++) {
			a[i] = Integer.parseInt(s[i-1]);
			if (!a[i]) f |= 1;
			else if (a[i] < 0) f |= 2;
			else ans += a[i];
		}
		if (!ans || !(f & 1)) { System.out.println("0"); return; }
		if (!(f & 2)) { System.out.println(ans); return; }

		for (close = 0, f = 0, i = 1; i <= w; i++) {
			if (!a[i]) close = Integer.MAX_VALUE, f = -1;
			else if (a[i] < 0) {
				if (f < 0 || close - (i-f) > -a[i]) close = -a[i], f = i;
			} else {
				if (f < 0) b[i] = Integer.MAX_VALUE;
				else {
					int k = close - (i-f); if (k < 0) k = 0;
					b[i] = k;
				}
			}
		}

		for (close = 0, f = w, i = w; i >= 1; i--) {
			if (!a[i]) close = Integer.MAX_VALUE, f = -1;
			else if (a[i] < 0) {
				if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
			} else {
				if (f < 0) b[i] = Integer.MAX_VALUE;
				else {
					int k = close - (f-i); if (k < 0) k = 0;
					if (k > b[i]) b[i] = k;
				}
			}
		}

		for (ans = 0, i = 1; i <= w; i++) {
			if (a[i] > 0) {
				if (b[i] > a[i]) ans += a[i];
				else             ans += b[i];
			}
		}
		System.out.println(ans);
	}
}

