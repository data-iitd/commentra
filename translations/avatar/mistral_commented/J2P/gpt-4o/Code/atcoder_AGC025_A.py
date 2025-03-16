# Importing the necessary module
import sys

# Method to find the sum of digits of a given number
def sum_of_digits(a):
    ans = 0  # Initialize answer variable
    while a >= 10:  # While number has digits greater than 0
        ans += a % 10  # Add current digit to answer
        a //= 10  # Remove current digit from number
    ans += a  # Add the last digit to answer
    return ans  # Return the sum of digits

# Main function starts here
def main():
    N = int(sys.stdin.readline().strip())  # Read the first integer from the standard input
    n = 0  # Initialize variable to store half of the number

    # Check if the number is even or odd and calculate n accordingly
    if N % 2 == 0:
        n = N // 2  # If even, n is the number divided by 2
    else:
        n = (N + 1) // 2  # If odd, n is the number divided by 2 and rounded up

    # Calculate the sum of digits of 1 and the number N-1
    ans = sum_of_digits(1) + sum_of_digits(N - 1)

    # Find the answer by checking all possible pairs of subarrays
    for A in range(1, n + 1):
        if sum_of_digits(A) + sum_of_digits(N - A) < ans:  # If the sum of digits of current subarray and its complement is less than the current answer
            ans = sum_of_digits(A) + sum_of_digits(N - A)  # Update the answer if a new pair is found with a greater sum

    # Print the answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
