/*
URL_HERE
*/

/*
This section includes necessary imports and defines various constants and functions.
*/
import sys
import math
import string
import itertools
import collections

# Function to read an integer from input
def readi():
    return int(sys.stdin.readline())

# Function to read a string from input
def reads():
    return sys.stdin.readline().strip()

# Function to read a list of integers from input
def readis():
    return [int(x) for x in sys.stdin.readline().split()]

# Function to read a list of strings from input
def readss():
    return sys.stdin.readline().strip().split()

# Function to read a list of lists of integers from input
def readllis():
    return [[int(x) for x in sys.stdin.readline().split()] for _ in range(readi())]

# Function to read a list of lists of strings from input
def readllss():
    return [[sys.stdin.readline().strip() for _ in range(readi())] for _ in range(readi())]

# Function to write an integer to output
def writei(x):
    sys.stdout.write(str(x) + ' ')

# Function to write a string to output
def writes(x):
    sys.stdout.write(x + ' ')

# Function to write a list of integers to output
def writel(x):
    for i in x: writei(i)
    writeln()

# Function to write a list of strings to output
def writess(x):
    for i in x: writes(i)
    writeln()

# Function to write a list of lists of integers to output
def writell(x):
    for i in x: writel(i)
    writeln()

# Function to write a list of lists of strings to output
def writelll(x):
    for i in x: writess(i)
    writeln()

# Function to write a newline to output
def writeln():
    sys.stdout.write('\n')

# Function to compute the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Function to compute the least common multiple (LCM)
def lcm(a, b):
    return a * b // gcd(a, b)

# Function to compute the modular inverse of a
def modinv(a, m):
    return expmod(a, m - 2, m)

# Function to compute modular exponentiation
def expmod(a, n, m):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return (expmod(a, n // 2, m) ** 2) % m
    else:
        return (a * expmod(a, n - 1, m)) % m

# Function to compute the binomial coefficient
def binom(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return math.factorial(n) // math.factorial(k) // math.factorial(n - k)

# Function to compute the binomial coefficient modulo m
def binommod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return expmod(n, m - 2, m) * expmod(k, m - 2, m) * expmod(n - k, m - 2, m) % m

# Function to compute the number of combinations
def comb(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return math.factorial(n) // math.factorial(k) // math.factorial(n - k)

# Function to compute the number of combinations modulo m
def combmod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return expmod(n, m - 2, m) * expmod(k, m - 2, m) * expmod(n - k, m - 2, m) % m

# Function to compute the number of permutations
def perm(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return math.factorial(n) // math.factorial(n - k)

# Function to compute the number of permutations modulo m
def permmod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return expmod(n, m - 2, m) * expmod(n - k, m - 2, m) % m

# Function to compute the number of derangements
def derangements(n):
    if n == 0:
        return 1
    else:
        return sum(derangements(n - 1) for i in range(n))

# Function to compute the number of derangements modulo m
def derangementsmod(n, m):
    if n == 0:
        return 1
    else:
        return sum(derangementsmod(n - 1, m) for i in range(n)) % m

# Function to compute the number of permutations with no fixed points
def derangements2(n):
    if n == 0:
        return 1
    else:
        return sum(derangements2(n - 1) for i in range(n))

# Function to compute the number of permutations with no fixed points modulo m
def derangements2mod(n, m):
    if n == 0:
        return 1
    else:
        return sum(derangements2mod(n - 1, m) for i in range(n)) % m

# Function to compute the number of permutations with exactly k fixed points
def derangements3(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements3(n - 1, k - 1) for i in range(n))

# Function to compute the number of permutations with exactly k fixed points modulo m
def derangements3mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements3mod(n - 1, k - 1, m) for i in range(n)) % m

# Function to compute the number of permutations with at least k fixed points
def derangements4(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements4(n - 1, k) for i in range(n - k))

# Function to compute the number of permutations with at least k fixed points modulo m
def derangements4mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements4mod(n - 1, k, m) for i in range(n - k)) % m

# Function to compute the number of permutations with at most k fixed points
def derangements5(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements5(n - 1, k) for i in range(k + 1))

# Function to compute the number of permutations with at most k fixed points modulo m
def derangements5mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return sum(derangements5mod(n - 1, k, m) for i in range(k + 1)) % m

# Function to compute the number of permutations with exactly k fixed points
def derangements6(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements3(n, k) - derangements4(n, k)

# Function to compute the number of permutations with exactly k fixed points modulo m
def derangements6mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements3mod(n, k, m) - derangements4mod(n, k, m) % m

# Function to compute the number of permutations with at least k fixed points
def derangements7(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements4(n, k) - derangements5(n, k)

# Function to compute the number of permutations with at least k fixed points modulo m
def derangements7mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements4mod(n, k, m) - derangements5mod(n, k, m) % m

# Function to compute the number of permutations with at most k fixed points
def derangements8(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements5(n, k) - derangements6(n, k)

# Function to compute the number of permutations with at most k fixed points modulo m
def derangements8mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements5mod(n, k, m) - derangements6mod(n, k, m) % m

# Function to compute the number of permutations with exactly k fixed points
def derangements9(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements6(n, k) - derangements7(n, k)

# Function to compute the number of permutations with exactly k fixed points modulo m
def derangements9mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements6mod(n, k, m) - derangements7mod(n, k, m) % m

# Function to compute the number of permutations with at least k fixed points
def derangements10(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements7(n, k) - derangements8(n, k)

# Function to compute the number of permutations with at least k fixed points modulo m
def derangements10mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements7mod(n, k, m) - derangements8mod(n, k, m) % m

# Function to compute the number of permutations with at most k fixed points
def derangements11(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements8(n, k) - derangements9(n, k)

# Function to compute the number of permutations with at most k fixed points modulo m
def derangements11mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements8mod(n, k, m) - derangements9mod(n, k, m) % m

# Function to compute the number of permutations with exactly k fixed points
def derangements12(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements9(n, k) - derangements10(n, k)

# Function to compute the number of permutations with exactly k fixed points modulo m
def derangements12mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements9mod(n, k, m) - derangements10mod(n, k, m) % m

# Function to compute the number of permutations with at least k fixed points
def derangements13(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements10(n, k) - derangements11(n, k)

# Function to compute the number of permutations with at least k fixed points modulo m
def derangements13mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements10mod(n, k, m) - derangements11mod(n, k, m) % m

# Function to compute the number of permutations with at most k fixed points
def derangements14(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements11(n, k) - derangements12(n, k)

# Function to compute the number of permutations with at most k fixed points modulo m
def derangements14mod(n, k, m):
    if k < 0 or k > n:
        return 0
    else:
        return derangements11mod(n, k, m) - derangements12mod(n, k, m) % m

# Function to compute the number of permutations with exactly k fixed points
def derangements15(n, k):
    if k < 0 or k > n:
        return 0
    else:
        return derangements12(n, k) - derangements13(n, k)

# Function to compute the number of permutations with exactly k fixed points modulo m
def derangements15mod(n, k, m):
    if k < 0 or k > n:
        r