# Import the necessary libraries
from typing import List

def main():
    n, k = map(int, input().split())  # Read the number of elements and the size of the subarray from the user

    l = list(map(int, input().split()))  # Read the elements into a list

    l.sort()  # Sort the list in ascending order

    ans = 0  # Initialize a variable to store the sum of the first k elements in descending order

    for i in range(k):  # Iterate through the last k elements in descending order
        ans += l[n - 1 - i]

    print(ans)  # Output the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
