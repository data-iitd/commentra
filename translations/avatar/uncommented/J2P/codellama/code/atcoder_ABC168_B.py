
import sys

K = int(sys.stdin.readline())
S = sys.stdin.readline()

if len(S) <= K:
    print(S)
else:
    print(S[:K] + "...")

