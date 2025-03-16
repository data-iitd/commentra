import sys

# Private function to compute the modular inverse using the Extended Euclidean Algorithm
def modInverse(a, m):
    m0 = m # Store the original modulus
    x0 = 0 # Initialize x0
    x1 = 1 # Initialize x1

    # If m is 1, the inverse is 0
    if m == 1:
        return 0

    # Apply the Extended Euclidean Algorithm
    while a > 1:
        q = a // m # Calculate quotient
        t = m # Store current modulus
        m = a % m # Update modulus
        a = t # Update a
        t = x0 # Store current x0
        x0 = x1 - q * x0 # Update x0
        x1 = t # Update x1

    # Ensure x1 is positive
    if x1 < 0:
        x1 += m0
    return x1 # Return the modular inverse

# Function to solve the Chinese Remainder Theorem (CRT)
def solveCRT(remainders, moduli):
    product = 1 # Variable to store the product of all moduli
    result = 0 # Variable to accumulate the result

    # Calculate the product of all moduli
    for mod in moduli:
        product *= mod

    # Calculate the result using the CRT formula
    for i in range(len(moduli)):
        partialProduct = product // moduli[i] # Calculate the partial product
        inverse = modInverse(partialProduct, moduli[i]) # Find the modular inverse
        result += remainders[i] * partialProduct * inverse # Update the result

    # Apply modulo to ensure the result is within the range of the product
    result = result % product
    if result < 0:
        result += product # Adjust result if it's negative
    return result # Return the final result

# Main function to execute the program
def main():
    n = int(input()) # Read the number of equations
    remainders = [] # List to store remainders
    moduli = [] # List to store moduli

    # Read each remainder and modulus pair
    for i in range(n):
        remainder = int(input()) # Read remainder
        modulus = int(input()) # Read modulus
        remainders.append(remainder) # Add remainder to the list
        moduli.append(modulus) # Add modulus to the list

    # Solve the CRT and print the smallest positive solution
    solution = solveCRT(remainders, moduli)
    print("Smallest positive solution: " + str(solution))

if __name__ == "__main__":
    main()

# 