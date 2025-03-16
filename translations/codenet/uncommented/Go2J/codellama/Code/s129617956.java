
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		int rt = (int) Math.sqrt(n);
		int minf = 100;
		for (int i = 1; i < rt + 1; i++) {
			if (n % i == 0) {
				int b = n / i;
				int ndigit = 0;
				for (; b > 0; b /= 10) {
					ndigit++;
				}
				minf = Math.min(minf, ndigit);
			}
		}
		System.out.println(minf);
	}
}

