package main;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			String str = sc.next();
			if (str.length() == 0) {
				break;
			}

			int[] memo = new int[26];
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if ('a' <= c && c <= 'z') {
					memo[c - 'a']++;
				} else if ('A' <= c && c <= 'Z') {
					memo[c - 'A']++;
				}
			}

			for (int i = 0; i < 26; i++) {
				System.out.printf("%c : %d\n", (char) (i + 'a'), memo[i]);
			}
		}
	}
}

// END-OF-CODE

// Translate the above Java code to C++ and end with comment "