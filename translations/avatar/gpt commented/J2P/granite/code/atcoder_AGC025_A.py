
import sys # Importing the sys module for input and output

def sum(a):
    ans = 0 # Initialize the sum to 0
    while a >= 10:
        ans += a % 10 # Add the last digit of a to ans
        a //= 10 # Remove the last digit from a
    ans += a # Add the remaining digit (which is less than 10) to ans
    return ans # Return the total sum of digits

def main():
    N = int(input()) # Read an integer input from the user
    n = N // 2 if N % 2 == 0 else (N + 1) // 2 # Determine the value of n based on whether N is even or odd
    ans = sum(1) + sum(N - 1) # Initialize ans with the sum of digits of 1 and N-1

    for A in range(1, n + 1): # Loop through all values from 1 to n
        if sum(A) + sum(N - A) < ans: # Check if the sum of digits of A and N-A is less than the current ans
            ans = sum(A) + sum(N - A) # Update ans with the new minimum sum

    print(ans) # Output the minimum sum of digits found

if __name__ == "__main__":
    main()

