def swap(x, y):
    # Function to swap two integers
    return y, x

def gcd(a, b):
    # Function to compute the greatest common divisor (GCD) of two numbers
    while b > 0:
        a, b = b, a % b
    return a  # Return the GCD

def upll(a):
    # Comparison function for sorting in ascending order
    return a

def downll(a):
    # Comparison function for sorting in descending order
    return -a

def sortup(arr):
    # Function to sort an array in ascending order
    arr.sort(key=upll)

def sortdown(arr):
    # Function to sort an array in descending order
    arr.sort(key=downll)

def modpow(a, n, mod):
    # Function to compute modular exponentiation
    ans = 1
    while n > 0:
        if n & 1:  # If n is odd
            ans = ans * a % mod  # Multiply the base with the result
        a = a * a % mod  # Square the base
        n //= 2  # Divide n by 2
    return ans  # Return the result

def modinv(a, mod):
    # Function to compute modular inverse using Fermat's little theorem
    return modpow(a, mod - 2, mod)  # a^(mod-2) mod mod

def max(a, b):
    # Function to return the maximum of two integers
    return b if a < b else a

def min(a, b):
    # Function to return the minimum of two integers
    return a if a < b else b

def chmax(a, b):
    # Function to update the value of a if b is greater
    if a[0] < b:
        a[0] = b  # Update a to b if b is greater

def chmin(a, b):
    # Function to update the value of a if b is smaller
    if a[0] > b:
        a[0] = b  # Update a to b if b is smaller

# Main function
if __name__ == "__main__":
    n = int(input())  # Read an integer n from input
    sum_digits = 0  # Initialize sum to 0
    m = n  # Store the original value of n

    # Calculate the sum of the digits of n (up to 9 digits)
    for _ in range(9):
        sum_digits += n % 10  # Add the last digit to sum
        n //= 10  # Remove the last digit

    # Check if m is divisible by the sum of its digits
    if m % sum_digits == 0:
        print("Yes")  # Print "Yes" if divisible
    else:
        print("No")  # Print "No" if not divisible

# <END-OF-CODE>
