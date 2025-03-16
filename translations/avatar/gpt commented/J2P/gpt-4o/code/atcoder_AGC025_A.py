# Importing the sys module for user input
import sys

# Function to calculate the sum of the digits of an integer 'a'
def sum_of_digits(a):
    ans = 0  # Initialize the sum to 0
    # Loop until 'a' is less than 10
    while a >= 10:
        ans += a % 10  # Add the last digit of 'a' to 'ans'
        a //= 10  # Remove the last digit from 'a'
    ans += a  # Add the remaining digit (which is less than 10) to 'ans'
    return ans  # Return the total sum of digits

# Main function
def main():
    N = int(sys.stdin.readline().strip())  # Read an integer input from the user
    n = 0  # Variable to hold half of N or adjusted value

    # Determine the value of n based on whether N is even or odd
    if N % 2 == 0:
        n = N // 2  # If N is even, set n to half of N
    else:
        n = (N + 1) // 2  # If N is odd, set n to the ceiling of half of N

    # Initialize ans with the sum of digits of 1 and N-1
    ans = sum_of_digits(1) + sum_of_digits(N - 1)

    # Loop through all values from 1 to n
    for A in range(1, n + 1):
        # Check if the sum of digits of A and N-A is less than the current ans
        if sum_of_digits(A) + sum_of_digits(N - A) < ans:
            ans = sum_of_digits(A) + sum_of_digits(N - A)  # Update ans with the new minimum sum

    # Output the minimum sum of digits found
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
