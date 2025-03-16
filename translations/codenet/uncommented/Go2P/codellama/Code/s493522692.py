
import sys
import math

#Util
def nextStr():
    return sys.stdin.readline().strip()

def nextInt():
    return int(sys.stdin.readline().strip())

def maxInt(a, b):
    if a > b:
        return a
    else:
        return b

def minInt(a, b):
    if a > b:
        return b
    else:
        return a

def absInt(a):
    if a >= 0:
        return a
    else:
        return -a

def absFloat64(a):
    if a >= 0:
        return a
    else:
        return -a

def maxFloat64(a, b):
    if a > b:
        return a
    else:
        return b

def minFloat64(a, b):
    if a > b:
        return b
    else:
        return a

def str2Int(s):
    return int(s)

def reverse(s):
    return s[::-1]

def powInt(p, q):
    return int(math.pow(p, q))

def isPrime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    b = True
    rootx = int(math.sqrt(x))
    i = 3
    for i in range(3, rootx+1, 2):
        if x % i == 0:
            b = False
            break
    return b

def PrimeFactors(n):
    pfs = []
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs.append(2)
        n = n / 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n))+1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs.append(i)
            n = n / i
    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        pfs.append(n)
    return pfs

def PrimeFactorsMap(n):
    pfs = {}
    # Get the number of 2s that divide n
    while n % 2 == 0:
        if 2 in pfs:
            pfs[2] += 1
        else:
            pfs[2] = 1
        #pfs = append(pfs, 2)
        n = n / 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n))+1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            if i in pfs:
                pfs[i] += 1
            else:
                pfs[i] = 1
            n = n / i
    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        if n in pfs:
            pfs[n] += 1
        else:
            pfs[n] = 1
    return pfs

def sumInts(x):

    total = 0
    for v in x:
        total += v

    return total

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(x, y):

    return x * y // gcd(x, y)

#Main
def main():
    # 'S'がN個、'c'がM個
    N, M = map(int, input().split())
    tmp = minInt(N, M//2)
    ans = 0
    ans += tmp
    N -= tmp
    M -= tmp * 2
    #fmt.Println(ans, N, M)
    print(ans + M//4)

if __name__ == "__main__":
    main()

