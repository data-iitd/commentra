import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int[] a = new int[w+1];
		int[] b = new int[w+1];
		int ans = 0;
		int f = 0, close = 0;
		for (int i = 1; i <= w; i++) {
			a[i] = sc.nextInt();
			if (a[i] == 0) {
				f |= 1;
				continue;
			}
			if (a[i] < 0) {
				if (f < 0 || close - (f-i) > -a[i]) close = -a[i];
				if (f < 0) f = -2;
			}
			ans += a[i];
		}
		if (!ans ||!(f & 1)) {
			System.out.println("0");
			return;
		}
		if (!(f & 2)) {
			System.out.println(ans);
			return;
		}
		for (int i = w; i >= 1; i--) {
			if (a[i] == 0) {
				close = INF;
				f = -1;
				continue;
			}
			if (a[i] < 0) {
				if (f < 0 || close - (f-i) > -a[i]) close = -a[i];
				if (f < 0) f = i;
			} else {
				b[i] = INF;
				if (f >= 0) {
					int k = close - (f-i);
					if (k < 0) k = 0;
					b[i] = k;
				}
			}
		}
		for (int i = 1; i <= w; i++) {
			if (a[i] > 0) {
				if (b[i] > a[i]) ans += a[i];
				else             ans += b[i];
			}
		}
		System.out.println(ans);
	}
}

