from sys import stdin
il = lambda func=int: list(map(func, stdin.readline().rstrip().split()))
ils = lambda n, s="int(input())": [eval(s) for _ in range(n)]
# il is a lambda function that reads input and converts it to a list of integers.
# ils is a lambda function that reads 'n' inputs from the user.

def gcd(a, b):
    if a < b: return gcd(b, a)
    if b == 0: return a
    return gcd(b, a%b)
def lcm(a, b):
    return a * b // gcd(a, b)
# gcd function calculates the greatest common divisor using the Euclidean algorithm.
# lcm function calculates the least common multiple using the gcd.

n, m = il()
s = input()
t = input()
# The program reads two integers n and m, and two strings s and t from the standard input.

aa = gcd(n, m)
bb = lcm(n, m)
cc = aa // bb
# The program calculates the gcd and lcm of n and m, and then computes the ratio of gcd to lcm.

for i in range(aa):
    if s[n//aa*i] != t[m//aa*i]:
        print(-1)
        exit()
# The program checks if the characters at the corresponding positions in s and t are the same.
# If any pair of characters do not match, it prints -1 and exits.

print(bb)
# If all characters match, the program prints the lcm of n and m.
