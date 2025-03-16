

import sys

def main():
    # Read input string S
    S = input()

    # Initialize variables l0 and l1 to store count of '0' and '1' respectively
    l0, l1 = 0, 0

    # Iterate through each character in string S
    for c in S:
        # If current character is '0', increment l0
        if c == '0':
            l0 += 1
        else:
            # Otherwise, increment l1
            l1 += 1

    # Print result which is twice the minimum of l0 and l1
    print(2 * min(l0, l1))

