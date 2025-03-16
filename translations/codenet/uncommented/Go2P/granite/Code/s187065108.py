
import sys

def scanInt():
    return int(input())

def scanString():
    return input()

def scanInts(n):
    return list(map(int, sys.stdin.readline().split()))

def scanStrings(n):
    return sys.stdin.readline().split()

def main():
    r, D, x = scanInt(), scanInt(), scanInt()
    for i in range(1, 11):
        x = r * x - D
        print(x)

