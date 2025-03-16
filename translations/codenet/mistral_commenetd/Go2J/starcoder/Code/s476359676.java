
import java.util.*;

public class Main {

	// Initialize a scanner for reading input from stdin
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		// Read the number of test cases
		int n = sc.nextInt();

		// Initialize variables for processing the input
		int ans = 0;
		int aPrev = 0;

		// Process each test case
		for (int i = 0; i < n; i++) {
			// Read the next integer as 'a'
			int a = sc.nextInt();

			// Check if 'a' is valid based on the conditions in the problem statement
			if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
				System.out.println(-1);
				return;
			} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
				ans++;
			} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
				ans += a;
			}

			// Update the previous number
			aPrev = a;
		}

		// Print the final answer
		System.out.println(ans);

		// End of code


C++:

#include <bits/stdc++.h>

using namespace std;

// Initialize a scanner for reading input from stdin
static int sc = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}()

int main() {
	// Read the number of test cases
	int n; cin >> n;

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a; cin >> a;

		// Check if 'a' is valid based on the conditions in the problem statement
		if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
			cout << -1 << endl;
			return 0;
		} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	cout << ans << endl;

	// End of code


C#:

using System;
using System.IO;
using System.Linq;

// Initialize a scanner for reading input from stdin
static TextReader cin = new StreamReader(Console.OpenStandardInput());

class MainClass {
	public static void Main (string[] args) {
		// Read the number of test cases
		int n = int.Parse(Console.ReadLine());

		// Initialize variables for processing the input
		int ans = 0;
		int aPrev = 0;

		// Process each test case
		for (int i = 0; i < n; i++) {
			// Read the next integer as 'a'
			int a = int.Parse(Console.ReadLine());

			// Check if 'a' is valid based on the conditions in the problem statement
			if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
				Console.WriteLine(-1);
				return;
			} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
				ans++;
			} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
				ans += a;
			}

			// Update the previous number
			aPrev = a;
		}

		// Print the final answer
		Console.WriteLine(ans);

		// End of code



# Initialize a scanner for reading input from stdin
import sys
import re

# Initialize a regular expression for parsing the input
regex = re.compile(r"(\d+)")

# Read the number of test cases
n = int(input())

# Initialize variables for processing the input
ans = 0
aPrev = 0

# Process each test case
for i in range(n):
	# Read the next integer as 'a'
	a = int(input())

	# Check if 'a' is valid based on the conditions in the problem statement
	if a > i or a > aPrev + 1: # 'a' is not valid, print -1 and exit
		print(-1)
		sys.exit()
	elif a == aPrev + 1: # Increment the answer if 'a' is consecutive with the previous number
		ans += 1
	else: # Add 'a' to the answer if it's not consecutive but greater than the previous number
		ans += a

	# Update the previous number
	aPrev = a

# Print the final answer
print(ans)

# End of code


JavaScript:

// Initialize a scanner for reading input from stdin
var sc = require('readline').createInterface({
	input: process.stdin,
	output: process.stdout
});

// Read the number of test cases
sc.once('line', function (n) {
	// Initialize variables for processing the input
	var ans = 0;
	var aPrev = 0;

	// Process each test case
	for (var i = 0; i < parseInt(n); i++) {
		// Read the next integer as 'a'
		sc.once('line', function (a) {
			// Check if 'a' is valid based on the conditions in the problem statement
			if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
				console.log(-1);
				return;
			} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
				ans++;
			} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
				ans += a;
			}

			// Update the previous number
			aPrev = a;

			// Check if this is the last test case
			if (i == parseInt(n) - 1) {
				// Print the final answer
				console.log(ans);
			}
		});
	}
});

// End of code


Ruby:

# Initialize a scanner for reading input from stdin
$stdin = File.open(0)

# Read the number of test cases
n = gets.to_i

# Initialize variables for processing the input
ans = 0
aPrev = 0

# Process each test case
for i in 0...n
	# Read the next integer as 'a'
	a = gets.to_i

	# Check if 'a' is valid based on the conditions in the problem statement
	if a > i or a > aPrev + 1
		# 'a' is not valid, print -1 and exit
		puts -1
		return
	elsif a == aPrev + 1
		# Increment the answer if 'a' is consecutive with the previous number
		ans += 1
	else
		# Add 'a' to the answer if it's not consecutive but greater than the previous number
		ans += a

	# Update the previous number
	aPrev = a

# Print the final answer
puts ans

# End of code


PHP:

<?php

// Initialize a scanner for reading input from stdin
$stdin = fopen("php://stdin", "r");

// Read the number of test cases
fscanf(STDIN, "%d\n", $n);

// Initialize variables for processing the input
$ans = 0;
$aPrev = 0;

// Process each test case
for ($i = 0; $i < $n; $i++) {
	// Read the next integer as 'a'
	fscanf(STDIN, "%d\n", $a);

	// Check if 'a' is valid based on the conditions in the problem statement
	if ($a > $i || $a > $aPrev + 1) { // 'a' is not valid, print -1 and exit
		echo "-1\n";
		return;
	} else if ($a == $aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
		$ans++;
	} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
		$ans += $a;
	}

	// Update the previous number
	$aPrev = $a;
}

// Print the final answer
echo $ans. "\n";

// End of code


C:

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner for reading input from stdin
static int sc = []() {
	int stdin_fd = 0;
	return scanf("%d", &stdin_fd) == 1 && stdin_fd;
}()

int main() {
	// Read the number of test cases
	int n; scanf("%d", &n);

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a; scanf("%d", &a);

		// Check if 'a' is valid based on the conditions in the problem statement
		if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
			printf("-1\n");
			return 0;
		} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	printf("%d\n", ans);

	// End of code


C++14:

#include <bits/stdc++.h>

using namespace std;

// Initialize a scanner for reading input from stdin
static int sc = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}()

int main() {
	// Read the number of test cases
	int n; cin >> n;

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a; cin >> a;

		// Check if 'a' is valid based on the conditions in the problem statement
		if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
			cout << -1 << endl;
			return 0;
		} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	cout << ans << endl;

	// End of code


C++17:

#include <iostream>

// Initialize a scanner for reading input from stdin
static int sc = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}()

int main() {
	// Read the number of test cases
	int n; cin >> n;

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a; cin >> a;

		// Check if 'a' is valid based on the conditions in the problem statement
		if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
			cout << -1 << endl;
			return 0;
		} else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		} else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	cout << ans << endl;

	// End of code


C++20:

#include <iostream>

// Initialize a scanner for reading input from stdin
static int sc = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}()

int main() {
	// Read the number of test cases
	int n; cin >> n;

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a; cin >> a;

		// Check if 'a' is valid based on the conditions