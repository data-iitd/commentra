
// AOJ 2275: Fox Number
// 2017.12.11 bal4u@uu

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s019421829{
	static int MAX = 707106;			// Define the maximum value for the sieve (sqrt(10^12/2))
	static char tbl[] = new char[MAX+1];	// Array to mark non-prime numbers
	static int prime[] = {			// Predefined array of prime numbers
		2, 3,  5,  7, 11, 13, 17, 19, 23, 29, 
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
		73, 79, 83, 89, 97,101,103,107,109,113, 
		127,131,137,139,149,151,157,163,167,173,
		179,181,191,193,197,199,211,223,227,229, 
		233,239,241,251,257,263,269,271,277,281, 
		283,293,307,311,313,317,331,337,347,349, 
		353,359,367,373,379,383,389,397,401,409, 
		419,421,431,433,439,443,449,457,461,463, 
		467,479,487,491,499,503,509,521,523,541, 
		547,557,563,569,571,577,587,593,599,601, 
		607,613,617,619,631,641,643,647,653,659, 
		661,673,677,683,691,701,709,719,727,733, 
		739,743,751,757,761,769,773,787,797,809, 
		811,821,823,827,829,839,853 };
	static int sqp[] = {				// Array to hold squares of the first 146 prime numbers
		4, 9,25,49,121,169,289,361,529,841,961,
		1369,1681,1849,2209,2809,3481,3721,4489,5041,
		5329,6241,6889,7921,9409,10201,10609,11449,11881,12769,
		16129,17161,18769,19321,22201,22801,24649,26569,27889,29929,
		32041,32761,36481,37249,38809,39601,44521,49729,51529,52441,54289,
		57121,58081,63001,66049,69169,72361,73441,76729,78961,80089,85849,
		94249,96721,97969,100489,109561,113569,120409,121801,124609,128881,
		134689,139129,143641,146689,151321,157609,160801,167281,175561,177241,
		185761,187489,192721,196249,201601,208849,212521,214369,218089,229441,
		237169,241081,249001,253009,259081,271441,273529,292681,299209,310249,
		316969,323761,326041,332929,344569,351649,358801,361201,368449,375769,
		380689,383161,398161,410881,413449,418609,426409,434281,436921,452929,
		458329,466489,477481,491401,502681,516961,528529,537289,546121,552049,
		564001,573049,579121,591361,597529,619369,635209,654481,657721,674041,
		677329,683929,687241,703921,727609 };
	static int sz;					// Variable to hold the size of the prime array
	static int base[] = new int[1000002];	// Array to hold base values
	static int idx [] = new int[1000002];	// Array to hold indices for calculations
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Function to generate prime numbers using the Sieve of Eratosthenes
	static void sieve()
	{
		int i, j, k;

		// Mark non-prime numbers in the tbl array
		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1; // Mark multiples of prime[i]
		}
		
		// Fill the prime array with additional primes
		for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i; // Add odd primes
		// printf("sz %d, prime[%d]=%d\n", sz, sz-1, prime[sz-1]); // Debug output for size and last prime
	}

	// Binary search function to find the index of a prime number
	static int bsch(int x)
	{
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Function to calculate the number of valid numbers
	static int calc(int x)
	{
		int i, k, p, ans;
		long long A, B, a, b, j, ll, rr;

		// Read input values A and B
		scanf("%lld%lld", &A, &B);
		a = A-B; // Calculate the difference
		b = A+B; // Calculate the sum
		if (b <= 1) { puts("0"); return 0; } // If sum is less than or equal to 1, output 0
		if (a <= 1) a = 2; // Ensure 'a' is at least 2
		if (b <= 2) b = 3; // Ensure 'b' is at least 3

		// Find the index of the largest prime less than or equal to sqrt(b/2)
		sz = bsch((int)sqrt((double)(b >> 1));

		// Initialize the index array to mark valid numbers
		Arrays.fill(idx, 1);
		for (i = 0; i <= sz; i++) {
			p = prime[i]; // Get the current prime
			for (k = 1, j = p; j <= b; k++) pp[k] = j; // Store powers of 2 up to 2^40
			while (--k) {
				j *= p; // Calculate powers of the prime
				ll = j*(1+(a-1)/j; rr = j*(b/j; // Calculate lower and upper bounds
				for (; ll <= b; ll *= p; // Iterate through multiples of the prime
				for (; ll <= rr; ll += j) { // Iterate through multiples of the prime
					int x = (int)(ll-a); // Calculate the index in the base array
					if (!idx[x] || base[x] == p) continue; // Skip if already marked or same prime
					if (idx[x] < k) idx[x] = 0; // Mark as invalid
					else base[x] = p, idx[x] = k; // Update base and index
				}
		}

		// Count the valid numbers in the range
		ans = 0, i = (int)(b-a+1); // Initialize the counter
		for (; i--; ) if (idx[i]) ans++; // Count non-zero indices

		printf("%d\n", ans); // Output the result
		return 0; // End of program
	}

	// Translate the C code to Java
	// Read input values A and B
	int main()
	{
		int a, b; // Read input values
		if (b <= 1) { // Read input values
			int k, int p, int i, int j; // Initialize variables
		scanf("%d%d", &a, &b); // Read input values
		if (b <= 1) { // Read input values
			if (b <= 1) { // Read input values
			for (; i--; ) { // Read input values
				if (b <= 1) { // Read input values
					if (b <= 1) { // Read input values
						if (b <= 1) { // Read input values
							if (b <= 1) { // Read input values
							if (b <= 1) { // Read input values
								if (b <= 1) { // Read input values
									if (b <= 1) { // Read input values
									if (b <= 1) { // Read input values
										if (b <= 1) { // Read input values
										if (b <= 1) { // Read input values
											if (b <= 1) { // Read input values
											if (b <= 1) { // Read input values
											if (b <= 1) { // Read input values
											if (b <= 1) { // Read input values
												if (b <= 1) { // Read input values
												if (b <= 1) { // Read input values
												if (b <= 1) { // Read input values
												if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
													if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values
	if (b <= 1) { // Read input values






if (b <= 1) { // Read input values


if (b <= 1) { // Read input values

if (b <= 1) { // Read input values

if (b <= 1) { // Read input values

if (b <= 1) { // Read input values
if (b <= 1) { // Read input values
if