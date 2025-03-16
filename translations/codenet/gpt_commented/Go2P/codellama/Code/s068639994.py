
#!/usr/bin/env python3

import sys

# mainFn contains the core logic of the program
def mainFn():
    # Read the number of elements
    n = int(sys.stdin.readline())
    # Read the integer slice from input
    ls = [int(x) for x in sys.stdin.readline().split()]
    # Create a reversed copy of the original slice
    lsRev = ls[::-1]
    # Sort the original slice in ascending order
    ls.sort()
    # Sort the reversed slice in descending order
    lsRev.sort(reverse=True)

    # Initialize the answer variable
    ans = 0
    # Iterate through all pairs of elements in the sorted slice
    for i in range(n):
        for j in range(i + 1, n):
            # Determine the minimum and maximum of the two selected elements
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            # Calculate the differences and sums needed for searching
            x, y = q - p, q + p

            # Find the left boundary for elements greater than x
            l = next((i for i, v in enumerate(ls) if v > x), n)
            # Find the right boundary for elements less than y
            r = n - next((i for i, v in enumerate(lsRev) if v < y), n)

            # Calculate the number of valid elements in the range
            sum = r - l
            # Adjust the count if the current indices are within the range
            if (i >= l) and (i <= r):
                sum -= 1
            if (j >= l) and (j <= r):
                sum -= 1
            # Ensure the sum is non-negative
            sum = max(0, sum)
            # Accumulate the result
            ans += sum

    # Divide the final answer by 3 as per the problem requirements
    ans //= 3
    # Output the result
    print(ans)

# min returns the smaller of two integers
def min(a, b):
    if a < b:
        return a
    return b

# max returns the larger of two integers
def max(a, b):
    if a > b:
        return a
    return b

# main is the entry point of the program
def main():
    # Call the main function to execute the logic
    mainFn()

if __name__ == '__main__':
    main()

