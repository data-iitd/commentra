import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int b = sc.nextInt();
			int e = sc.nextInt();
			for (int j = b; j < e; j++) {
				int t = a[j];
				a[j] = a[e-1-j];
				a[e-1-j] = t;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				System.out.print(" ");
			}
			System.out.print(a[i]);
		}
		System.out.println();
	}
}

