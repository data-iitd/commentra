# Import the necessary libraries
import sys

def main():
    n, k = map(int, sys.stdin.readline().split())  # Read the values of n and k from standard input
    l = list(map(int, sys.stdin.readline().split()))  # Read each element into the list

    l.sort()  # Sort the list in ascending order

    ans = sum(l[-k:])  # Sum the largest k elements

    print(ans)  # Output the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
