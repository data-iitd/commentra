
import sys
from collections import Counter

def main():
    n = int(input()) # Read the number of elements
    a = list(map(int, input().split())) # Read the array elements and convert them to a list
    s = Counter() # Initialize the Counter

    def is_possible(k):
        s.clear() # Clear the Counter for new calculations
        current = 0 # Initialize current value

        for ai in a:
            if ai <= current:
                if k == 1: return False

                while s[ai] >= k:
                    s[ai] -= 1
                    ai += 1

                s[ai] += 1
                current = ai
            else:
                current = ai

        return True

    ng = 0 # Lower bound for binary search
    ok = n # Upper bound for binary search

    while ok - ng > 1:
        k = (ng + ok) // 2 # Calculate mid-point
        if is_possible(k):
            ok = k # If possible, adjust upper bound
        else:
            ng = k # If not possible, adjust lower bound

    print(ok) # Output the result

if __name__ == "__main__":
    main()

