# Function to swap two integers
def swap(x, y):
    return y, x  # Return the swapped values

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    while b > 0:
        a, b = b, a % b  # Update a and b
    return a  # Return the GCD

# Comparator function for sorting in ascending order
def upll(x):
    return x

# Comparator function for sorting in descending order
def downll(x):
    return -x

# Function to sort an array in ascending order
def sortup(arr):
    arr.sort(key=upll)

# Function to sort an array in descending order
def sortdown(arr):
    arr.sort(key=downll)

# Function to calculate a^n modulo m
def modpow(a, n, mod):
    ans = 1  # Initialize the answer as 1
    while n > 0:
        if n & 1:  # Check if n is odd
            ans = ans * a % mod  # Multiply the answer with a and take modulo m
        a = a * a % mod  # Square a and take modulo m
        n //= 2  # Divide n by 2
    return ans  # Return the final answer

# Function to find the modular multiplicative inverse of a modulo m
def modinv(a, mod):
    return modpow(a, mod - 2, mod)

# Function to find the maximum of two integers
def max_val(a, b):
    return b if a < b else a  # Return the maximum

# Function to find the minimum of two integers
def min_val(a, b):
    return a if a < b else b  # Return the minimum

# Function to update the value of a variable with the maximum of the current value and a new value
def chmax(a, b):
    if a[0] < b:  # If the current value is smaller than the new value
        a[0] = b  # Update the current value with the new value

# Function to update the value of a variable with the minimum of the current value and a new value
def chmin(a, b):
    if a[0] > b:  # If the current value is greater than the new value
        a[0] = b  # Update the current value with the new value

# Main function
def main():
    n = int(input())  # Read the number of digits from the standard input
    sum_digits = 0  # Variable to store the sum of digits
    m = n  # Initialize m with the given number

    # Calculate the sum of digits
    for _ in range(9):
        sum_digits += m % 10  # Add the last digit to the sum
        m //= 10  # Remove the last digit and update m

    # Check if the given number is divisible by the sum of its digits
    if n % sum_digits == 0:
        print("Yes")  # If yes, print "Yes"
    else:
        print("No")  # If no, print "No"

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
