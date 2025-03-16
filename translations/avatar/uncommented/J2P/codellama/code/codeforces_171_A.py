
import sys
import math

def fast_input():
    sys.stdin = open("input.txt", "r")
    sys.setrecursionlimit(10**7)
    return sys.stdin.readline

def fast_output():
    sys.stdout = open("output.txt", "w")
    return sys.stdout.write

input = fast_input()
write = fast_output()

def reverse(n):
    if n < 10:
        return n * 10
    t = n
    r = 0
    while t > 0:
        r = (r * 10) + t % 10
        t = t // 10
    return r

n = int(input())
m = int(input())
t = reverse(m)
write(str(t + n) + "\n")

# 