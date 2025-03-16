import math

MAX = 707106  # sqrt(10^12/2)
tbl = [0] * (MAX + 1)

# Initialize variable 'sz' to store the size of the prime array
sz = 0
# Declare an array 'prime' of size 57100 to store prime numbers
prime = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
    547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
    607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
    661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
    739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853
]

def sieve():
    global sz
    # Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
    for i in range(1, 147):
        k = prime[i]  # Get the current prime number
        for j in range(k * k, MAX + 1, k):
            tbl[j] = 1  # Mark all multiples of 'k' as composite in 'tbl'
    
    # Find all prime numbers greater than sqrt(MAX)
    for i in range(146, MAX + 1):
        if not tbl[i]:
            prime.append(i)
            sz += 1

base = [0] * 1000002
idx = [1] * 1000002
pp = [0] * 41  # 2^40 = 1099511627776 >= 10^12

def bsch(x):
    l, r = 0, sz
    # Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
    while l < r:
        m = (l + r) // 2  # Calculate the middle index 'm'
        if prime[m] == x:
            return m  # If 'x' is a prime number, return its index
        if prime[m] < x:
            l = m + 1  # If 'prime[m]' is smaller than 'x', 'l' should be updated
        else:
            r = m  # Otherwise, 'r' should be updated
    return l - 1  # Return the index of the largest prime number 'p' such that 'p^2 <= x'

def main():
    global sz
    sieve()  # Call the Sieve of Eratosthenes algorithm to find prime numbers

    A, B = map(int, input().split())  # Read two integers 'A' and 'B' from the standard input
    a = A - B
    b = A + B
    if b <= 1:
        print(0)
        return  # If 'b' is less than or equal to 1, output '0' and terminate the program
    if a <= 1:
        a = 2  # If 'a' is less than or equal to 1, set it to 2

    sz = bsch(int(math.sqrt(b // 2)))  # Find the largest prime number 'p' such that 'p^2 <= b'

    for i in range(sz + 1):
        p = prime[i]  # Get the current prime number
        k = 1
        j = p
        while j <= b:
            pp[k] = j
            k += 1
            j *= p
        for k in range(k - 1, -1, -1):
            j = pp[k]
            ll = j * (1 + (a - 1) // j)
            rr = j * (b // j)
            while ll <= rr:
                x = ll - a  # Calculate the index 'x' of the segment
                if not idx[x] or base[x] == p:
                    ll += j
                    continue  # If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
                base[x] = p
                idx[x] = k
                ll += j

    ans = 0
    i = b - a + 1  # Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
    while i > 0:
        i -= 1
        if idx[i]:
            ans += 1  # Increment 'ans' if the current segment has been processed
    print(ans)  # Output the result 'ans' and terminate the program

if __name__ == "__main__":
    main()

# <END-OF-CODE>
