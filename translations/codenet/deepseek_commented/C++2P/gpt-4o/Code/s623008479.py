# Import the necessary modules
from typing import List

def main():
    n, k = map(int, input().split())  # Read the values of n and k from the input
    l = list(map(int, input().split()))  # Read the elements of the list l

    l.sort()  # Sort the list l in ascending order

    ans = 0  # Initialize ans to 0
    for i in range(k):
        ans += l[n - 1 - i]  # Sum the last k elements of the sorted list

    print(ans)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
