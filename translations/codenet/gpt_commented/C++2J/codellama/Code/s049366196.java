#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;

// Define long long type for convenience
typedef long long ll;

// Macro to simplify usage of vector iterators
#define ALL(v) (v).begin(), (v).end()

// Constants for infinity and modulo operations
const int inf = 1e9;
const int mod = 1e9 + 7;

// Function to check if a number is prime
boolean is_prime(ll x) {
    // Check divisibility from 2 to the square root of x
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false; // If divisible, not prime
	return true; // If no divisors found, it is prime
}

public class Main {
    public static void main(String[] args) {
        // Read the input value N
		int N;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

        // Initialize the answer variable to 1
		ll ans = 1;

        // Loop through all numbers from 2 to N
		for (int i = 2; i <= N; i++) {
            // Check if the current number i is prime
			if (is_prime((ll)i)) {
                // Store the original value of N for calculations
				int NN = N;
                // Initialize a counter for the prime factor's exponent
				int cnt = 0;

                // Count the number of times i is a factor in the numbers from 1 to N
				while (NN) {
					cnt += NN / i; // Count multiples of i
					NN /= i; // Reduce NN by dividing by i
				}

                // Update the answer by multiplying with the count of factors + 1
				ans *= cnt + 1;
				ans %= mod; // Take modulo to prevent overflow
			}
		}

        // Output the final result
		System.out.println(ans);
    }
}

