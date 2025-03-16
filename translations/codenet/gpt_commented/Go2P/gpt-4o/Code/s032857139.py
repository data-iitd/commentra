import sys
import math
from typing import List

# Constants for the program
MOD = 1000000000 + 7

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def read_int_slice(n: int) -> List[int]:
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Read input values for n and x
    n, x = read_int(), read_int()
    A = read_int_slice(n)

    # Sort the array A
    A.sort()

    # Initialize answer variable
    ans = 0
    # Count how many elements can be taken from A without exceeding x
    for i in range(n):
        if x >= A[i]:
            ans += 1
            x -= A[i]
        else:
            break
    # Adjust answer if all elements are taken and there is still remaining x
    if ans == n and x > 0:
        ans -= 1
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
