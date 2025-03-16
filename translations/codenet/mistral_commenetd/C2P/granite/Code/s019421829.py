
import math

MAX = 707106
tbl = [0] * (MAX + 1)
prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853]
sz = 0

def sieve():
    global sz
    i, j, k = 0, 0, 0

    # Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
    while i < 147:
        k = prime[i]  # Get the current prime number
        for j in range(sqp[i], MAX, k):
            tbl[j] = 1  # Mark all multiples of 'k' as composite in 'tbl' array
        i += 1

    # Find all prime numbers greater than sqrt(MAX)
    while sz < 146:
        i += 1
        if tbl[i] == 0:
            prime[sz] = i
            sz += 1

def bsch(x):
    l, r = 0, sz
    while l < r:
        m = (l + r) // 2
        if prime[m] == x:
            return m
        if prime[m] < x:
            l = m + 1
        else:
            r = m
    return l - 1

sieve()  # Call the Sieve of Eratosthenes algorithm to find prime numbers

A, B = map(int, input().split())  # Read two integers 'A' and 'B' from the standard input
a, b = A - B, A + B  # Calculate 'a' = 'A' - 'B' and 'b' = 'A' + 'B'
if b <= 1:
    print(0)  # If 'b' is less than or equal to 1, output '0' and terminate the program
if a <= 1:
    a = 2  # If 'a' is less than or equal to 1, set it to 2

sz = bsch(math.isqrt(b))  # Find the largest prime number 'p' such that 'p^2 <= b' using binary search

idx = [1] * (b - a + 1)  # Initialize all elements of 'idx' array to 1
base = [0] * (b - a + 1)  # Initialize all elements of 'base' array to 0

for i in range(sz + 1):
    p = prime[i]  # Get the current prime number
    pp = [p ** k for k in range(1, 41)]  # Calculate all powers of 'p' less than or equal to 'b'
    for k, j in enumerate(pp):
        ll, rr = j * (1 + (a - 1) // j), j * (b // j)  # Calculate the lower and upper bounds of the segment to search for 'a' in
        for x in range(ll - a, rr - a + 1):
            if idx[x] == 0 or base[x] == p:
                continue  # If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
            base[x] = p  # Otherwise, set the prime number at 'x' to 'p'
            idx[x] = k  # Set the index of 'x' to 'k'

ans = sum(1 for x in idx if x!= 0)  # Count the number of segments that have been processed
print(ans)  # Output the result 'ans' and terminate the program

