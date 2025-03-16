import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int[] a = new int[w+2];
		int[] b = new int[w+2];
		int ans = 0, f = 0, close = 0, i, k, f1, f2;
		for (i = 1; i <= w; i++) {
			a[i] = sc.nextInt();
			if (a[i] == 0) f |= 1;
			else if (a[i] < 0) f |= 2;
			else ans += a[i];
		}
		if (ans == 0 || (f & 1) == 0) {
			System.out.println("0");
			return;
		}
		if ((f & 2) == 0) {
			System.out.println(ans);
			return;
		}
		for (i = 1; i <= w; i++) {
			if (a[i] == 0) close = INF;
			else if (a[i] < 0) {
				if (f1 < 0 || close - (i-f1) > -a[i]) {
					close = -a[i];
					f1 = i;
				}
			} else {
				if (f1 < 0) b[i] = INF;
				else {
					k = close - (i-f1);
					if (k < 0) k = 0;
					b[i] = k;
				}
			}
		}
		for (i = w; i >= 1; i--) {
			if (a[i] == 0) close = INF;
			else if (a[i] < 0) {
				if (f2 < 0 || close - (f2-i) > -a[i]) {
					close = -a[i];
					f2 = i;
				}
			} else {
				if (f2 < 0) b[i] = INF;
				else {
					k = close - (f2-i);
					if (k < 0) k = 0;
					if (k > b[i]) b[i] = k;
				}
			}
		}
		for (i = 1; i <= w; i++) {
			if (a[i] > 0) {
				if (b[i] > a[i]) ans += a[i];
				else             ans += b[i];
			}
		}
		System.out.println(ans);
	}
}

