# Import the sys module for reading input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read an integer n from the user
    ans = 0  # Initialize the variable ans to 0

    # Loop from 1 to n (inclusive)
    for i in range(1, n + 1):
        # Calculate a value based on the current value of i and the variable n
        term = n // i
        sum_terms = term * (term + 1) // 2
        ans += i * sum_terms

    # Print the value of ans
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
