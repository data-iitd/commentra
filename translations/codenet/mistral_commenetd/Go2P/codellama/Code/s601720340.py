
import sys
import math

def solve():
    # INPUT PARSING
    X = int(sys.stdin.readline().strip())
    N = int(sys.stdin.readline().strip())
    p = [int(x) for x in sys.stdin.readline().strip().split()]

    # OUTPUT GENERATION PART
    ans = 0
    print(ans)

    # If ans > 0, print "Yes" and exit; otherwise, print "No"
    if ans > 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    solve()

