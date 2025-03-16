#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX  707106			// sqrt(10^12/2)
char tbl[MAX+1];

int sz;						// max sz = 57084, prime[0] = 2, prime[57083] = 707099
int prime[57100] = {  		// prime[146] = 853, prime[147] = 857
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

int sz;						// Initialize variable'sz' to store the size of the prime array
int prime[57100];			// Declare an array 'prime' of size 57100 to store prime numbers
// Initialize the prime array with the first few prime numbers
// The rest of the prime numbers will be calculated using the Sieve of Eratosthenes algorithm

def sieve():
	i, j, k
	# Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
	for i in range(1, 147):
		k = prime[i]			# Get the current prime number
		for j in range(sqp[i], MAX, k): tbl[j] = 1	# Mark all multiples of 'k' as composite in 'tbl' array
	# Find all prime numbers greater than sqrt(MAX)
	for sz = 146, i = 853; i <= MAX; i += 2:
		if not tbl[i]: prime[sz++] = i	# If 'i' is not marked as composite, it is a prime number

#	print("sz %d, prime[%d]=%d" % (sz, sz-1, prime[sz-1]))
#	        sz 57084, prime[57083]=707099

def bsch(x):
	m, l, r
	# Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
	l = 0; r = sz
	while l < r:
		m = (l + r) >> 1		# Calculate the middle index'm'
		if prime[m] == x: return m	# If 'x' is a prime number, return its index
		if prime[m] < x: l = m + 1	# If 'prime[m]' is smaller than 'x', 'l' should be updated
		else r = m			# Otherwise, 'r' should be updated
	return l-1				# Return the index of the largest prime number 'p' such that 'p^2 <= x'

def main():
	i, k, p, ans
	A, B, a, b, j, ll, rr
	# Read two integers 'A' and 'B' from the standard input
	A, B = map(int, input().split())
	a = A-B; b = A+B		# Calculate 'a' = 'A' - 'B' and 'b' = 'A' + 'B'
	if b <= 1: print("0"); return 0	# If 'b' is less than or equal to 1, output '0' and terminate the program
	if a <= 1: a = 2		# If 'a' is less than or equal to 1, set it to 2

	sz = bsch(int(sqrt(b/2)))	# Find the largest prime number 'p' such that 'p^2 <= b' using binary search

	idx = [1] * (b+1)		# Initialize all elements of 'idx' array to 1
	base = [0] * (b+1)		# Initialize all elements of 'base' array to 0

	for i in range(0, sz):
		p = prime[i]			# Get the current prime number
		for k in range(1, 41): pp[k] = p**k	# Calculate all powers of 'p' less than or equal to 'b'
		for k in range(40, 0, -1):
			j = pp[k]; ll = j*(1+(a-1)/j); rr = j*(b/j)	# Calculate the lower and upper bounds of the segment to search for 'a' in
			for ll in range(ll, rr+1, j):
				x = int(ll-a)	# Calculate the index 'x' of the segment
				if not idx[x] or base[x] == p: continue	# If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
				base[x] = p; idx[x] = k	# Otherwise, set the prime number at 'x' to 'p' and its index to 'k'
	ans = 0; i = int(b-a+1)	# Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
	while i:
		if idx[i]: ans += 1	# Increment 'ans' if the current segment has been processed
		i -= 1
	print(ans)			# Output the result 'ans' and terminate the program

if __name__ == "__main__":
	main()

