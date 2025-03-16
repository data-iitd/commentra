import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		int a[] = new int[n];
		int b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			if (a[i] % 2 == 0) {
				b++;
			}
			else {
				c++;
			}
		}

		long bsum = 0, csum = 0;
		bsum = (long)Math.pow(2, b);

		if (p == 0) {
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 0) {
					csum += nCr(c, i);
				}
			}
		}
		else {
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 1) {
					csum += nCr(c, i);
				}
			}
		}

		long ans = bsum*csum;
		System.out.println(ans);
	}

	public static long nPr(long n, long r) {
		long res = 1;
		for (int i = 0; i < r; i++) {
			res *= (n - i);
		}

		return res;
	}

	public static long nCr(long n, long r) {
		//long res = nPr(n, r) / nPr(r, r);
		double res = 1;
		for (int i = 0; i < r; i++) {
			res *= (n - i);
			res /= (i+1);
		}
		return (long)res;
	}
}

