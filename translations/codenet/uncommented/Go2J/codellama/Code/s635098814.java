
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		while (sc.hasNext()) {
			String str = sc.nextLine();
			char[] S = str.toCharArray();
			if (S.length == 0) {
				break;
			}
			for (int i = 0; i < S.length; i++) {
				char c = S[i];

				if ('a' <= c && c <= 'z') {
					// toUpper
					// c-('a'-'A')
					memo[c - 'a']++;
				} else if ('A' <= c && c <= 'Z') {
					// toLower
					// c+('a'-'A')
					memo[c - 'A']++;
				} else {
					// stay
					// c
					continue;
				}
			}
		}

		for (int i = 0; i < ALPHABET_NUM; i++) {
			System.out.printf("%c : %d\n", (char) (i + 'a'), memo[i]);
		}
	}

	// MODはとったか？
	// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

	// END-OF-CODE
}