import sys

def main():
    input = sys.stdin.readline
    A, B, C = map(int, input().split())
    if B - A == C - B:
        print("YES")
    else:
        print("NO")

