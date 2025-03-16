import sys

def main():
    N = int(input().strip())  # Read the integer N from standard input
    count = 0  # Initialize a counter to count the number of digits in N
    temp = N  # Initialize a temporary variable to hold the value of N
    ans = 0  # Initialize a variable to accumulate the result

    # Calculate the number of digits in N
    while temp > 0:
        temp //= 10
        count += 1

    # Iterate from 1 to the number of digits in N
    for i in range(1, count + 1):
        if i == count:  # Check if it's the last digit
            if i % 2 == 1:  # Check if the position is odd
                ans += (N - 10 ** (i - 1) + 1)  # Add the count of numbers with odd positions
        else:
            if i == 1:  # Check if it's the first digit
                ans += 9  # Add the count of single-digit numbers
            elif i % 2 == 1:  # Check if the position is odd
                ans += (10 ** i - 10 ** (i - 1))  # Add the count of numbers in odd positions

    print(ans)  # Print the result

if __name__ == "__main__":
    main()
