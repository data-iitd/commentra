import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int[] b = new int[n];
		int j = 0;
		for (int i = 0; i < n; i++) {
			int v = a[i];
			int x = Arrays.binarySearch(b, 0, j, v);
			if (x < 0) {
				x = -x - 1;
			}
			if (x == j) {
				b[j] = v;
				j++;
			} else {
				b[x] = v;
			}
		}
		System.out.println(j);
	}
}

