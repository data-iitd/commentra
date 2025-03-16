

import sys
import heapq

def main():
    # Read the number of elements
    N = int(input())

    # Initialize a list to store numbers
    nums = []

    # Read each number and add it to the list
    for i in range(N):
        num = int(input())
        nums.append(num)

    # Initialize variables to keep track of the current index and the count of differences
    bin = 0
    diff = 0

    # Loop until the list is empty
    while nums:
        # Retrieve the next number and its index from the list
        num = heapq.heappop(nums)
        idx = nums.index(num)

        # If the current index is not even when bin is even (or vice versa), increment the diff counter
        if (bin % 2)!= (idx % 2):
            diff += 1

        # Update bin and take modulo 2 to keep it within 0 or 1
        bin += 1
        bin %= 2

    # Calculate the answer by dividing diff by 2
    ans = diff // 2

    # Print the result
    print(ans)

if __name__ == "__main__":
    main()

