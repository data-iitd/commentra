# AOJ 2275: Fox Number
# 2017.12.11 bal4u@uu

import sys

# Define the maximum value for the sieve (sqrt(10^12/2))
MAX = 707106

# Array to mark non-prime numbers
tbl = [0] * (MAX+1)

# Variable to hold the size of the prime array
sz = 0

# Predefined array of prime numbers
prime = [
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
811,821,823,827,829,839,853 ]

# Array to hold squares of the first 146 prime numbers
sqp = [
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
677329,683929,687241,703921,727609 ]

# Function to generate prime numbers using the Sieve of Eratosthenes
def sieve():
	i, j, k
	for i in range(1, 147):
		k = prime[i]
		for j in range(sqp[i], MAX, k): tbl[j] = 1
	for i in range(853, MAX, 2):
		if not tbl[i]: prime[sz] = i; sz += 1

# Arrays to hold base values and indices for calculations
base = [0] * (1000002)
idx  = [0] * (1000002)
pp   = [0] * 41

# Binary search function to find the index of a prime number
def bsch(x):
	m, l, r = 0, 0, sz
	while l < r:
		m = (l + r) >> 1
		if prime[m] == x: return m
		if prime[m] < x: l = m + 1
		else: r = m
	return l-1

def main():
	i, k, p, ans
	A, B, a, b, j, ll, rr
	sieve()
	A, B = map(int, sys.stdin.readline().split())
	a = A-B
	b = A+B
	if b <= 1: print(0); return
	if a <= 1: a = 2
	sz = bsch(int(sqrt(b/2)))
	for i in range(sz+1): idx[i] = 1
	for i in range(sz):
		p = prime[i]
		for k in range(1, 41): pp[k] = p * (1+(a-1)/p)
		while k:
			j = pp[k]; ll = j*(1+(a-1)/j); rr = j*(b/j)
			while ll <= rr:
				x = int(ll-a)
				if not idx[x] or base[x] == p:
					ll += j; continue
				if idx[x] < k: idx[x] = 0
				else: base[x] = p; idx[x] = k
				ll += j
	ans = 0; i = int(b-a+1)
	while i:
		if idx[i]: ans += 1
		i -= 1
	print(ans)

# 