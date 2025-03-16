package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			String str = sc.next();

			if (str.length() == 0) {
				break;
			}

			char[] S = str.toCharArray();

			for (int i = 0; i < S.length; i++) {
				char c = S[i];

				if (c >= 'a' && c <= 'z') {
					// toUpper
					// c-('a'-'A')
					memo[c-'a']++;
				} else if (c >= 'A' && c <= 'Z') {
					// toLower
					// c+('a'-'A')
					memo[c-'A']++;
				} else {
					// stay
					// c
					continue;
				}
			}
		}

		for (int i = 0; i < memo.length; i++) {
			System.out.printf("%c : %d\n", (char)(i+'a'), memo[i]);
		}
	}
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

