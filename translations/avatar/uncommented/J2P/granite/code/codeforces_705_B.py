
import sys
import math
import bisect
import re

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        A = list(map(int, input().split()))
        prev_winner = 0
        for i in range(n):
            if A[i] == 1:
                if prev_winner == 0:
                    prev_winner = 2
            if prev_winner == 2 or prev_winner == 0:
                if (A[i] - 1) % 2 == 0:
                    print(2)
                    prev_winner = 2
                else:
                    print(1)
                    prev_winner = 1
            else:
                if (A[i] - 1) % 2 == 0:
                    print(1)
                    prev_winner = 1
                else:
                    print(2)
                    prev_winner = 2

if __name__ == "__main__":
    main()

