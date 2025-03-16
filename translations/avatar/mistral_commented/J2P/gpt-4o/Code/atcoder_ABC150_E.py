import sys

# Function to calculate the power of a number x raised to the power n
def power(x, n, mod):
    if n == 0:  # Base case when n is 0
        return 1

    val = power(x, n // 2, mod)  # Recursively calculating the square of x raised to the power n//2

    # If n is odd, multiplying the result with x
    if n % 2 == 1:
        val = (val * x) % mod

    return val

# Main function to start the execution of the program
def main():
    input = sys.stdin.read
    data = input().splitlines()  # Reading all input lines

    n = int(data[0])  # Parsing the first line of input as an integer representing the size of the array
    c = list(map(int, data[1].split()))  # Reading the second line of input and converting it to a list of integers

    mod = 1000000007  # Defining a constant value for modulus

    # Checking if the size of the array is 1
    if n == 1:
        # Printing the result for the case when the size of the array is 1
        print(c[0] * 2 % mod)
        return  # Exiting the function after printing the result

    # Sorting the array c
    c.sort()

    # Calculating the values of b and a
    b = power(2, n, mod)
    a = power(2, n - 2, mod)

    # Initializing the variable ans to 0
    ans = 0

    # Iterating through the array from index 2 to n+1
    for i in range(2, n + 2):
        # Calculating the value of val using the current index i and the previously calculated value a
        val = a * i % mod

        # Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i]

        # Taking the modulus of the product to ensure the result is within the range of modulus
        val %= mod

        # Adding the value of val to the variable ans
        ans += val

        # Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= mod

    # Multiplying the value of ans with the value of b
    ans *= b

    # Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= mod

    # Printing the final result
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
