

# Python code

# Function to swap two integers
def swap(x, y):
    temp = x  # Store the value of x in temp
    x = y  # Assign the value of y to x
    y = temp  # Assign the value of temp (i.e., the original value of x) to y

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    c = a % b  # Calculate the remainder
    a = b  # Update a with the value of b
    b = c  # Update b with the value of the previous remainder
    while b > 0:
        c = a % b  # Calculate the remainder
        a = b  # Update a with the value of b
        b = c  # Update b with the value of the previous remainder
    return a  # Return the GCD (i.e., the last non-zero value of a)

# Comparator function for sorting in ascending order
def up(a, b):
    return a < b

# Comparator function for sorting in descending order
def down(a, b):
    return a > b

# Function to sort an array in ascending order using the built-in sort() function
def sortup(a):
    a.sort()

# Function to sort an array in descending order using the built-in sort() function
def sortdown(a):
    a.sort(reverse=True)

# Function to calculate a^n modulo m
def modpow(a, n, mod):
    ans = 1  # Initialize the answer as 1
    while n > 0:
        if n & 1:  # Check if n is odd
            ans = (ans * a) % mod  # Multiply the answer with a and take modulo m
        a = (a * a) % mod  # Square a and take modulo m
        n //= 2  # Divide n by 2
    return ans  # Return the final answer

# Function to find the modular multiplicative inverse of a modulo m
def modinv(a, mod):
    return modpow(a, mod - 2, mod)

# Function to find the maximum of two integers
def max(a, b):
    if a < b:  # If a is smaller than b
        return b  # Return b as the maximum
    else:  # If a is greater than or equal to b
        return a  # Return a as the maximum

# Function to find the minimum of two integers
def min(a, b):
    if a < b:  # If a is smaller than b
        return a  # Return a as the minimum
    else:  # If a is greater than or equal to b
        return b  # Return b as the minimum

# Function to update the value of a variable with the maximum of the current value and a new value
def chmax(a, b):
    if a < b:  # If the current value is smaller than the new value
        a = b  # Update the current value with the new value
    return a  # Return the updated value

# Function to update the value of a variable with the minimum of the current value and a new value
def chmin(a, b):
    if a > b:  # If the current value is greater than the new value
        a = b  # Update the current value with the new value
    return a  # Return the updated value

# Main function
def main():
    n = int(input("Enter the number of digits in the given number: "))  # Read the number of digits from the user
    m = int(input("Enter the given number: "))  # Read the given number from the user
    sum = 0  # Initialize sum with 0
    for i in range(9):
        sum += m % 10  # Add the last digit to the sum
        m //= 10  # Remove the last digit and update m
    if m % sum == 0:  # Check if the given number is divisible by the sum of its digits
        print("Yes")  # If yes, print "Yes"
    else:
        print("No")  # If no, print "No"

if __name__ == "__main__":
    main()  # Call the main function

# The above code now includes comments for each logical block. These comments should help in understanding the code better.