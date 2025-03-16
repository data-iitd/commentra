#include <iostream>
#include <map>

using u64 = unsigned long long;

const u64 B = 13131; // Define a constant base for hashing
const int N = 500000 + 7; // Define the maximum length of the string + 7 for safety

int n; // Declare an integer to store the length of the string
char s[N]; // Declare a character array to store the input string
u64 f[N]; // Declare an array of u64 to store the hash values
int g[N]; // Declare an array of integers to store position-dependent values
std::map<u64, u64> map; // Declare a map to store the frequency of hash values
u64 cnt; // Declare a u64 to count the number of valid substrings

// Define the pow function to calculate a^k using binary exponentiation
u64 pow(u64 a, u64 k) {
	if (k < 0) k += (1llu << 63) - 1; // Handle negative exponents
	u64 t = 1; // Initialize the result to 1
	for (; k; a = a * a, k >>= 1) // Square and halve the exponent
		if (k & 1) t = t * a; // If the exponent is odd, multiply the result
	return t; // Return the result
}

// Main function to execute the program
int main() {
	// Uncomment the following lines if you want to read from a file and write to a file
	// freopen("code.in", "r", stdin);
	// freopen("code.out", "w", stdout);

	scanf("%d%s", &n, s + 1); // Read the input values for n and the string s
	for (int i = 1; i <= n; ++i) // Iterate through the string
		if (s[i] == '+' || s[i] == '-') // Check if the character is '+' or '-'
			f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]); // Compute the hash value
		else
			f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1); // Update the position-dependent values
	for (int i = n; i; --i) // Iterate through the string in reverse
		++map[f[i]], cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]; // Count the valid substrings
	printf("%lld\n", cnt); // Print the count of valid substrings

	return 0; // Return 0 to indicate successful execution
}
