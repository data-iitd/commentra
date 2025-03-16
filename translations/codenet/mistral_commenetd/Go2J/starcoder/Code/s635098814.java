package main;

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read input until EOF.
		while (sc.hasNext()) {
			String str = sc.next();

			// Count occurrences of each letter.
			int[] memo = new int[26];
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);

				if ('a' <= c && c <= 'z') {
					// Increment count for lowercase letters.
					memo[c - 'a']++;
				} else if ('A' <= c && c <= 'Z') {
					// Increment count for uppercase letters.
					memo[c - 'A']++;
				} else {
					// Ignore non-alphabet characters.
					continue;
				}
			}

			// Print the count of each letter.
			for (int i = 0; i < memo.length; i++) {
				System.out.printf("%c : %d\n", (char) (i + 'a'), memo[i]);
			}
		}
	}
}

// END-OF-CODE

/*******************************************************************/

// Python:
# -*- coding: utf-8 -*-

import sys

# Read input until EOF.
for line in sys.stdin:
	# Count occurrences of each letter.
	memo = [0] * 26
	for c in line:
		if 'a' <= c and c <= 'z':
			# Increment count for lowercase letters.
			memo[ord(c) - ord('a')] += 1
		elif 'A' <= c and c <= 'Z':
			# Increment count for uppercase letters.
			memo[ord(c) - ord('A')] += 1
		else:
			# Ignore non-alphabet characters.
			continue

	# Print the count of each letter.
	for i in range(26):
		print(chr(i + ord('a')) +':'+ str(memo[i]))
