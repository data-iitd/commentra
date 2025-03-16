
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				continue;
			}
			sum += i;
		}
		System.out.println(sum);
	}
}

// 