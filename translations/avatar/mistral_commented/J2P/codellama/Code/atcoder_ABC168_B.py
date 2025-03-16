
import sys

K = int(sys.stdin.readline().strip())

S = sys.stdin.readline().strip()

if len(S) <= K:

    print(S)

else:

    print(S[:K] + "...")

