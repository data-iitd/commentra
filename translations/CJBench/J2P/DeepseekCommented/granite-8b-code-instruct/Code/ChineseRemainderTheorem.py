

import sys

def solveCRT(remainders, moduli):
    product = 1
    result = 0

    # Calculate the product of all moduli
    for mod in moduli:
        product *= mod

    # Iterate through each modulus and calculate the partial solution
    for i in range(len(moduli)):
        partialProduct = product // moduli[i]
        inverse = modInverse(partialProduct, moduli[i])
        result += remainders[i] * partialProduct * inverse

    # Reduce the result modulo the product of all moduli
    result = result % product

    # Ensure the result is positive
    if result < 0:
        result += product

    return result

# Calculates the modular multiplicative inverse
def modInverse(a, m):
    m0 = m
    x0 = 0
    x1 = 1

    # Base case for the algorithm
    if m == 1:
        return 0

    # Extended Euclidean Algorithm
    while a > 1:
        q = a // m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t

    # Make sure x1 is positive
    if x1 < 0:
        x1 += m0

    return x1

# Entry point of the program
if __name__ == "__main__":
    n = int(input())
    remainders = []
    moduli = []

    # Read the remainders and moduli from the user
    for i in range(n):
        remainder = int(input())
        modulus = int(input())
        remainders.append(remainder)
        moduli.append(modulus)

    # Solve the CRT and print the result
    solution = solveCRT(remainders, moduli)
    print("Smallest positive solution:", solution)

Translate the above Python code to C++ and end with comment "