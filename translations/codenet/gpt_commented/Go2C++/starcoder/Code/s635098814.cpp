#include <bits/stdc++.h>

using namespace std;

// Constants
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = 1e18;
const int INF_BIT60 = 1 << 60;

// Global variables
int memo[ALPHABET_NUM];
string str;

int main() {
	// Read input until EOF
	while (true) {
		cin >> str;
		if (str == "") {
			break;
		}

		// Count occurrences of each letter
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];

			if (c >= 'a' && c <= 'z') {
				// Increment count for lowercase letters
				memo[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				// Increment count for uppercase letters
				memo[c - 'A']++;
			} else {
				// Ignore non-alphabet characters
				continue;
			}
		}
	}

	// Print the count of each letter
	for (int i = 0; i < ALPHABET_NUM; i++) {
		cout << (char)(i + 'a') << " : " << memo[i] << endl;
	}
}

// END-OF-CODE

/*******************************************************************/

// Python:
# -*- coding: utf-8 -*-

# Constants
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1e18
INF_BIT60 = 1 << 60

# Global variables
memo = [0] * ALPHABET_NUM
str = ""

def main():
	# Read input until EOF
	while (True):
		str = input()
		if (str == ""):
			break

		# Count occurrences of each letter
		for i in range(len(str)):
			c = str[i]

			if (c >= 'a' and c <= 'z'):
				# Increment count for lowercase letters
				memo[ord(c) - ord('a')] += 1
			elif (c >= 'A' and c <= 'Z'):
				# Increment count for uppercase letters
				memo[ord(c) - ord('A')] += 1
			else:
				# Ignore non-alphabet characters
				continue

	# Print the count of each letter
	for i in range(ALPHABET_NUM):
		print(chr(i + ord('a')), ":", memo[i])

if __name__ == "__main__":
	main()

# END-OF-CODE

/*******************************************************************/

// C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

// Constants
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = 1e18;
const long long INF_BIT60 = 1 << 60;

// Global variables
int[] memo = new int[ALPHABET_NUM];
string str;

class Program {
	static void Main(string[] args) {
		// Read input until EOF
		while (true) {
			str = Console.ReadLine();
			if (str == "") {
				break;
			}

			// Count occurrences of each letter
			for (int i = 0; i < str.Length; i++) {
				char c = str[i];

				if (c >= 'a' && c <= 'z') {
					// Increment count for lowercase letters
					memo[c - 'a']++;
				} else if (c >= 'A' && c <= 'Z') {
					// Increment count for uppercase letters
					memo[c - 'A']++;
				} else {
					// Ignore non-alphabet characters
					continue;
				}
			}
		}

		// Print the count of each letter
		for (int i = 0; i < ALPHABET_NUM; i++) {
			Console.WriteLine((char)(i + 'a') + " : " + memo[i]);
		}
	}
}

// END-OF-CODE

/*******************************************************************/

// Java:
import java.util.*;
import java.io.*;

// Constants
final int MOD = 1000000000 + 7;
final int ALPHABET_NUM = 26;
final long INF_INT64 = 1e18;
final long INF_BIT60 = 1 << 60;

// Global variables
int[] memo = new int[ALPHABET_NUM];
String str;

public class Main {
	public static void main(String[] args) {
		// Read input until EOF
		while (true) {
			str = new BufferedReader(new InputStreamReader(System.in)).readLine();
			if (str.equals("")) {
				break;
			}

			// Count occurrences of each letter
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);

				if (c >= 'a' && c <= 'z') {
					// Increment count for lowercase letters
					memo[c - 'a']++;
				} else if (c >= 'A' && c <= 'Z') {
					// Increment count for uppercase letters
					memo[c - 'A']++;
				} else {
					// Ignore non-alphabet characters
					continue;
				}
			}
		}

		// Print the count of each letter
		for (int i = 0; i < ALPHABET_NUM; i++) {
			System.out.println((char)(i + 'a') + " : " + memo[i]);
		}
	}
}

// END-OF-CODE

/*******************************************************************/

// JavaScript:
var fs = require("fs");

// Constants
var MOD = 1000000000 + 7;
var ALPHABET_NUM = 26;
var INF_INT64 = 1e18;
var INF_BIT60 = 1 << 60;

// Global variables
var memo = new Array(ALPHABET_NUM);
var str;

function main() {
	// Read input until EOF
	while (true) {
		str = fs.readFileSync("/dev/stdin").toString().trim();
		if (str == "") {
			break;
		}

		// Count occurrences of each letter
		for (var i = 0; i < str.length; i++) {
			var c = str[i];

			if (c >= 'a' && c <= 'z') {
				// Increment count for lowercase letters
				memo[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
			} else if (c >= 'A' && c <= 'Z') {
				// Increment count for uppercase letters
				memo[c.charCodeAt(0) - 'A'.charCodeAt(0)]++;
			} else {
				// Ignore non-alphabet characters
				continue;
			}
		}
	}

	// Print the count of each letter
	for (var i = 0; i < ALPHABET_NUM; i++) {
		console.log(String.fromCharCode(i + 'a') + " : " + memo[i]);
	}
}

if (require.main === module) {
	main();
}

// END-OF-CODE

/*******************************************************************/

// Ruby:
# -*- coding: utf-8 -*-

# Constants
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1e18
INF_BIT60 = 1 << 60

# Global variables
memo = [0] * ALPHABET_NUM
str = ""

def main()
  # Read input until EOF
  while (true)
    str = gets.chomp
    if str == ""
      break

    # Count occurrences of each letter
    for i in 0...str.length
      c = str[i]

      if ('a' <= c && c <= 'z')
        # Increment count for lowercase letters
        memo[c.ord - 'a'.ord] += 1
      elsif ('A' <= c && c <= 'Z')
        # Increment count for uppercase letters
        memo[c.ord - 'A'.ord] += 1
      else
        # Ignore non-alphabet characters
        next
      end
    end
  end

  # Print the count of each letter
  for i in 0...ALPHABET_NUM
    print(i.chr + " : " + memo[i])
  end
end

main()

# END-OF-CODE

/*******************************************************************/

// C:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1e18
#define INF_BIT60 1 << 60

// Global variables
int memo[ALPHABET_NUM];
char str[1000000];

int main() {
	// Read input until EOF
	while (scanf("%s", str)!= EOF) {
		// Count occurrences of each letter
		for (int i = 0; i < strlen(str); i++) {
			char c = str[i];

			if (c >= 'a' && c <= 'z') {
				// Increment count for lowercase letters
				memo[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				// Increment count for uppercase letters
				memo[c - 'A']++;
			} else {
				// Ignore non-alphabet characters
				continue;
			}
		}
	}

	// Print the count of each letter
	for (int i = 0; i < ALPHABET_NUM; i++) {
		printf("%c : %d\n", i + 'a', memo[i]);
	}

	return 0;
}

// END-OF-CODE

/*******************************************************************/

// Pascal:
program main;

// Constants
const MOD = 1000000000 + 7;
const ALPHABET_NUM = 26;
const INF_INT64 = 1e18;
const INF_BIT60 = 1 << 60;

// Global variables
var memo: array[ALPHABET_NUM] of integer;
var str: string;

begin
  // Read input until EOF
  while not eof(input) do
  begin
    readln(str);

    // Count occurrences of each letter
    for i := 0 to length(str) - 1 do
    begin
      var c := str[i];

      if c in ['a'..'z'] then
      begin
        // Increment count for lowercase letters
        memo[ord(c) - ord('a')] += 1;
      end
      else if c in ['A'..'Z'] then
      begin
        // Increment count for uppercase letters
        memo[ord(c) - ord('A')] += 1;
      end
      else
      begin
        // Ignore non-alphabet characters
        continue;
      end
    end
  end;

  // Print the count of each letter
  for i := 0 to ALPHABET_NUM - 1 do
  begin
    write(chr(i + ord('a')),': ', memo[i], eol);
  end;
end.

// END-OF-CODE

/*******************************************************************/

// Objective-C:
#import <stdio.h>
#import <stdlib.h>
#import <string.h>

// Constants
#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1e18
#define INF_BIT60 1 << 60

// Global variables
int memo[ALPHABET_NUM];
char str[1000000];

int main() {
	// Read input until EOF
	while (scanf("%s", str)!= EOF) {
		// Count occurrences of each letter
		for (int i = 0; i < strlen(str); i++) {
			char c = str[i];

			if (c >= 'a' && c <= 'z') {
				// Increment count for lowercase letters
				memo[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				// Increment count for uppercase letters
				memo[c - 'A']++;
			} else {
				// Ignore non-alphabet characters
				continue;
			}
		}
	}

	// Print the count of each letter
	for (int i = 0; i < ALPHABET_NUM; i++) {
		printf("%c : %d\n", i + 'a', memo[i]);
	}

	return 0;
}

// END-OF-CODE

/*******************************************************************/

// Prolog:
% 数学関数
% 最大公約数
gcd(X, Y, R) :- R is X mod Y, X > Y.
gcd(X, Y, R) :- gcd(Y, X mod Y, R).

% 最小公倍数
lcm(X, Y, R) :- gcd(X, Y, R), R * X = Y * R.

% 素因数分解
prime_factorize(N, L) :- prime_factorize(N, 2, L).
prime_factorize(1, _, []).
prime_factorize(N, I, L) :- I * I < N, mod(N, I) =:= 0, N1 is N div I, prime_factorize(N1, I, L), L = [I|L1],!.
prime_factorize(N, I, L) :- I * I < N, prime_factorize(N, I + 1, L).

% 素数判定
is_prime(N) :- N > 1, prime_factorize(N, L), length(L, 1).

% 約数列挙
divisors(N, L) :- divisors(N, 1, L).
divisors(N, I, L) :- I * I < N, mod(N, I) =:= 0, N1 is N div I, divisors(N1, I, L), L = [I|L1],!.
divisors(N, I, L) :- I * I < N, I =< N, divisors(N, I + 1, L).

% 約数の個数
divisor_count(N, C) :- divisors(N, L), length(L, C).

% 階乗
factorial(0, 1).
factorial(N, R) :- N > 0, N1 is N - 1, factorial(N1, R1), R is N * R1.

% 階乗の逆元
inverse_factorial(N, R) :- N > 0, factorial(N, R1), R is R1 ** (-1).

% 階乗の二項係数
binomial_coefficient(N, K, R) :- N >= 0, K >= 0, N1 is N - 1, binomial_coefficient(N1, K, R1), R is R1 * (N1 - K + 1) / N.

% 総和
sum(N, R) :- sum(N, 0, R).
sum(0, R, R).
sum(N, R0, R