

import sys

def main():
    # Step 1: Read the input value `n` which represents the number of elements.
    n = int(input())

    # Step 2: Read the values of `v` (values) and store them in a list `vList`.
    vList = list(map(int, input().split()))

    # Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    cList = list(map(int, input().split()))

    # Step 4: Initialize a variable `max` to keep track of the maximum profit.
    max = 0

    # Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for i in range(n):
        profit = vList[i] - cList[i]
        if profit > 0:
            max += profit

    # Step 6: Print the maximum profit.
    print(max)

if __name__ == "__main__":
    main()

