// AOJ 2275: Fox Number
// 2017.12.11 bal4u@uu

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		// Read input values A and B
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long a = A-B; // Calculate the difference
		long b = A+B; // Calculate the sum
		if (b <= 1) { System.out.println("0"); return; } // If sum is less than or equal to 1, output 0
		if (a <= 1) a = 2; // Ensure 'a' is at least 2

		// Find the index of the largest prime less than or equal to sqrt(b/2)
		int sz = bsch((int)Math.sqrt((double)(b >> 1)));

		// Initialize the index array to mark valid numbers
		int[] idx = new int[1000002];
		Arrays.fill(idx, 1);
		for (int i = 0; i <= sz; i++) {
			int p = prime[i]; // Get the current prime
			for (int k = 1, j = p; j <= b; j *= p) pp[k++] = j; // Store powers of the prime
			while (--k) {
				j = pp[k], ll = j*(1+(a-1)/j), rr = j*(b/j); // Calculate lower and upper bounds
				for (; ll <= rr; ll += j) { // Iterate through multiples of the prime
					int x = (int)(ll-a); // Calculate the index in the base array
					if (idx[x] == 0 || base[x] == p) continue; // Skip if already marked or same prime
					if (idx[x] < k) idx[x] = 0; // Mark as invalid if fewer powers
					else base[x] = p, idx[x] = k; // Update base and index
				}
			}
		}

		// Count the valid numbers in the range
		int ans = 0, i = (int)(b-a+1); while (i-- > 0) if (idx[i]!= 0) ans++; // Count non-zero indices
		System.out.println(ans); // Output the result
	}

	// Arrays to hold base values and indices for calculations
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Binary search function to find the index of a prime number
	static int bsch(int x) {
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Arrays to hold prime numbers
	static int prime[] = {
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

	// Function to generate prime numbers using the Sieve of Eratosthenes
	static void sieve() {
		int i, j, k;

		// Mark non-prime numbers in the tbl array
		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1; // Mark multiples of prime[i]
		}
		
		// Fill the prime array with additional primes
		for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i; // Add odd primes
	}

	// Arrays to hold base values and indices for calculations
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Binary search function to find the index of a prime number
	static int bsch(int x) {
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Arrays to hold prime numbers
	static int prime[] = {
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

	// Function to generate prime numbers using the Sieve of Eratosthenes
	static void sieve() {
		int i, j, k;

		// Mark non-prime numbers in the tbl array
		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1; // Mark multiples of prime[i]
		}
		
		// Fill the prime array with additional primes
		for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i; // Add odd primes
	}

	// Arrays to hold base values and indices for calculations
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Binary search function to find the index of a prime number
	static int bsch(int x) {
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Arrays to hold prime numbers
	static int prime[] = {
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

	// Function to generate prime numbers using the Sieve of Eratosthenes
	static void sieve() {
		int i, j, k;

		// Mark non-prime numbers in the tbl array
		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1; // Mark multiples of prime[i]
		}
		
		// Fill the prime array with additional primes
		for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i; // Add odd primes
	}

	// Arrays to hold base values and indices for calculations
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Binary search function to find the index of a prime number
	static int bsch(int x) {
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Arrays to hold prime numbers
	static int prime[] = {
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

	// Function to generate prime numbers using the Sieve of Eratosthenes
	static void sieve() {
		int i, j, k;

		// Mark non-prime numbers in the tbl array
		for (i = 1; i < 147; i++) {
			k = prime[i];
			for (j = sqp[i]; j < MAX; j += k) tbl[j] = 1; // Mark multiples of prime[i]
		}
		
		// Fill the prime array with additional primes
		for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i; // Add odd primes
	}

	// Arrays to hold base values and indices for calculations
	static int base[] = new int[1000002];
	static int idx[] = new int[1000002];
	static long pp[] = new long[41];		// Array to hold powers of 2 up to 2^40

	// Binary search function to find the index of a prime number
	static int bsch(int x) {
		int m, l = 0, r = sz;

		// Perform binary search on the prime array
		while (l < r) {
			m = (l + r) >> 1; // Calculate mid-point
			if (prime[m] == x) return m; // Found the prime
			if (prime[m] < x) l = m + 1; else r = m; // Adjust search range
		}
		return l-1; // Return the index of the largest prime less than x
	}

	// Arrays to hold prime numbers
	static int prime[] = {
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
661,673,6