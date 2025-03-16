import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] as = new int[n];
		for (int i = 0; i < n; i++) {
			as[i] = sc.nextInt();
		}
		Arrays.sort(as);
		int[] xs = new int[n];
		xs[0] = as[0];
		for (int j = 1; j < n; j++) {
			int idx = Arrays.binarySearch(xs, 0, j, as[j]);
			if (idx < 0) {
				idx = -idx - 1;
			}
			xs[idx] = as[j];
		}
		System.out.println(j);
	}
}

