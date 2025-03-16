#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Include necessary headers for the program

typedef long long ll;
typedef vector<ll> vll;
typedef set<ll> sll;

// Define aliases for common data types and containers

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Define helper functions for gcd and lcm

map<ll, ll> getPrimeFactor(ll n) {
	map<ll, ll> res;
	// Initialize an empty map to store prime factors and their exponents

	for (ll i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			// If the number is divisible by 'i', add it to the map with its exponent incremented

			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	// If the number is not 1, add it to the map with exponent 1

	return res;
}

// Function to get prime factors of a number

bool IsPrimeNumber(ll num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	// Check if the number is prime by checking divisibility up to its square root

	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// Function to check if a number is prime

ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	// Extended Euclidean Algorithm to find modular multiplicative inverse

	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	// Make the result positive and less than 'm'

	if (u < 0) u += m;
	return u;
}

// Function to find modular multiplicative inverse

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

// Macros for for loops

int main() {
	ll N, K;
	// Declare variables for input

	scanf("%lld %lld", &N, &K);
	// Read input for 'N' and 'K'

	vll A(N + 1);
	// Initialize an array 'A' of size 'N+1'

	repeq(i, 1, N) {
		scanf("%lld", &A[i]);
		// Read input for each element of the array 'A'
	}

	ll cur = 1;
	// Initialize a variable 'cur' to keep track of the current position in the array

	vll dic(N + 1, -1);
	// Initialize an array 'dic' of size 'N+1' to store the distance from the start for each position

	bool flg = false;
	// Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

	repeq(i, 1, K) {
		if (dic[cur] < 0 || flg) {
			dic[cur] = i;
			// If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

			cur = A[cur];
			// Move to the next position
		}
		else if(!flg) {
			ll tmp = K - (dic[cur] - 1);
			tmp %= i - dic[cur];
			// Calculate the number of steps we need to take to reach the position 'i' from the current position

			i = K - tmp ;
			// Update 'i' to the position we need to reach

			flg = true;
		}
	}

	printf("%lld\n", cur);
	// Print the final answer, which is the position of the last visited node

	return 0;
}
// Main function to solve the problem

