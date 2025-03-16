
import sys

# Function to calculate the power of a number x raised to the power n
def power(x, n):
    if n == 0: # Base case when n is 0
        return 1
    mod = 1000000007 # Defining a constant value for modulus
    val = power(x, n // 2) # Recursively calculating the square of x raised to the power n/2
    if n % 2 == 1: # If n is odd, multiplying the result with x
        val = (val * x) % mod
    return val

# Main method to start the execution of the program
def main():
    n = int(input()) # Reading the first line of input as an integer representing the size of the array
    c = list(map(int, input().split())) # Reading the second line of input and splitting it into a list of integers

    # Checking if the size of the array is 1
    if n == 1:
        # Printing the result for the case when the size of the array is 1
        print((c[0] * 2) % 1000000007)
        return # Exiting the method after printing the result

    # Sorting the list c in parallel using the built-in sorted() function
    c.sort()

    # Calculating the values of b and a
    b = power(2, n)
    a = power(2, n - 2)

    # Initializing the variable ans to 0
    ans = 0

    # Iterating through the list c from index 2 to n+1
    for i in range(2, n + 2):
        # Calculating the value of val using the current index i and the previously calculated value a
        val = (a * i) % 1000000007
        # Multiplying the value of val with the current element of the list c[n+1-i]
        val = (val * c[n + 1 - i]) % 1000000007
        # Adding the value of val to the variable ans
        ans = (ans + val) % 1000000007

    # Multiplying the value of ans with the value of b
    ans = (ans * b) % 1000000007

    # Printing the final result
    print(ans)

# Calling the main method to start the execution of the program
if __name__ == "__main__":
    main()

