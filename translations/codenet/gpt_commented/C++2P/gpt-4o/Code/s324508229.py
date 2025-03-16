# Import necessary libraries
import sys

# Define the main function
def main():
    n = int(input())  # Read the upper limit of the range

    # Initialize a 2D array to count occurrences of digit pairs
    cnt = [[0] * 10 for _ in range(10)]  # Set all counts to zero

    # Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
    for i in range(1, n + 1):
        b = i % 10  # Get the last digit of the number
        a = i  # Store the original number
        while a >= 10:  # Extract the first digit
            a //= 10  # Divide by 10 until we get the first digit
        cnt[a][b] += 1  # Increment the count for the pair (first digit, last digit)

    ans = 0  # Initialize the answer variable to accumulate results

    # Calculate the total number of valid pairs by multiplying counts
    for i in range(1, 10):  # Iterate over possible first digits
        for j in range(1, 10):  # Iterate over possible last digits
            ans += cnt[i][j] * cnt[j][i]  # Add the product of counts for pairs (i, j) and (j, i)

    print(ans)  # Output the final result

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
