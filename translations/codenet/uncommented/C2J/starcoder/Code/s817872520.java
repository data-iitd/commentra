// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		int w, i, k, f, close, ans;
		Scanner sc = new Scanner(System.in);

		w = sc.nextInt();
		sc.nextLine();
		ans = 0;
		f = 0;
		for (i = 1; i <= w; i++) {
			k = sc.nextInt();
			if (!k) f |= 1;
			else if (k < 0) f |= 2;
			else ans += k;
		}
		if (!ans ||!(f & 1)) { System.out.println("0"); return; }
		if (!(f & 2)) { System.out.println(ans); return; }

		for (close = 0, f = 0, i = 1; i <= w; i++) {
			if (!k) close = INF, f = -1;
			else if (k < 0) {
				if (f < 0 || close - (i-f) > -k) close = -k, f = i;
			} else {
				if (f < 0) b[i] = INF;
				else {
					k = close - (i-f); if (k < 0) k = 0;
					b[i] = k;
				}
			}
		}

		for (close = 0, f = w, i = w; i >= 1; i--) {
			if (!k) close = INF, f = -1;
			else if (k < 0) {
				if (f < 0 || close - (f-i) > -k) close = -k, f = i;
			} else {
				if (f < 0) b[i] = INF;
				else {
					k = close - (f-i); if (k < 0) k = 0;
					if (k > b[i]) b[i] = k;
				}
			}
		}

		for (ans = 0, i = 1; i <= w; i++) {
			if (k > 0) {
				if (b[i] > k) ans += k;
				else             ans += b[i];
			}
		}
		System.out.println(ans);
	}
}

