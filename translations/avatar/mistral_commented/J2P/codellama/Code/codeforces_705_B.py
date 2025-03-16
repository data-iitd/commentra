
import sys

def solve():
    t = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    prev_winner = 0

    for i in range(t):
        if arr[i] == 1:
            if prev_winner == 0:
                prev_winner = 2
            if (i - 1) % 2 == 0:
                print(prev_winner == 0 and 2 or 1)
                prev_winner = prev_winner == 0 and 2 or 1

solve()

