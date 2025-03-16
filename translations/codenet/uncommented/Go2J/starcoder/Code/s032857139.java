package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int x = Integer.parseInt(br.readLine());
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(A);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (x >= A[i]) {
				ans++;
				x -= A[i];
			} else {
				break;
			}
		}
		if (ans == n && x > 0) {
			ans--;
		}
		System.out.println(ans);
	}
}

