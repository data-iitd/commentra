

import sys

def solveCRT(remainders, moduli):
    # Function to solve the Chinese Remainder Theorem problem
    product = 1 # Initialize product to 1
    result = 0 # Initialize result to 0

    for mod in moduli:
        # Multiply all moduli to get the product
        product *= mod

    for i in range(len(moduli)):
        # Calculate the partial product and inverse for each modulus
        partialProduct = product // moduli[i]
        inverse = modInverse(partialProduct, moduli[i])

        # Update the result by adding the product of the remainders, partial product and inverse
        result += remainders[i] * partialProduct * inverse

    # Calculate the final result by taking the remainder of the result with the product
    result = result % product

    # If the result is negative, add the product to make it positive
    if result < 0:
        result += product

    # Return the final result
    return result

def modInverse(a, m):
    # Function to calculate the modular inverse of 'a' with respect to'm'
    m0 = m # Save the original value of'm'
    x0 = 0 # Initialize 'x0' to 0
    x1 = 1 # Initialize 'x1' to 1

    if m == 1:
        # If'm' is 1, return 0 as the modular inverse of any number is 0
        return 0

    while a > 1:
        # Calculate the quotient and update 'a' and'm'
        q = a // m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t

    # If 'x1' is negative, add the original value of'm' to make it positive
    if x1 < 0:
        x1 += m0

    # Return the modular inverse
    return x1

if __name__ == "__main__":
    # Main function to read input and call the solveCRT function
    n = int(input()) # Read the number of pairs (remainder, modulus)

    remainders = [] # Initialize an empty list to store remainders
    moduli = [] # Initialize an empty list to store moduli

    for i in range(n):
        # Read each pair (remainder, modulus) and add them to the respective lists
        remainder = int(input())
        modulus = int(input())
        remainders.append(remainder)
        moduli.append(modulus)

    solution = solveCRT(remainders, moduli) # Call the solveCRT function to find the solution

    print("Smallest positive solution:", solution) # Print the solution to the console

Translate the above Python code to C++ and end with comment "