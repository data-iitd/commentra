# Import necessary libraries
from collections import defaultdict

# Define a constant size for the count array
SIZE = int(1e5 * 2) + 13

# Declare a dictionary to hold the counts of each number
cnt = defaultdict(int)

def main():
    # Read the number of elements (n) and the number of largest counts to keep (k)
    n, k = map(int, input().split())

    # Read n integers and count their occurrences
    for _ in range(n):
        x = int(input())
        # Increment the count for the number x
        cnt[x] += 1

    # Transfer the counts of numbers that appeared at least once to a list
    a = [count for count in cnt.values()]

    # Initialize the answer variable to accumulate the result
    ans = 0
    # Sort the counts in ascending order
    a.sort()

    # Calculate the number of counts to exclude (m) based on k
    m = len(a) - k
    # Sum the counts of the smallest m elements
    for i in range(m):
        ans += a[i]  # Add the count to the answer

    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
