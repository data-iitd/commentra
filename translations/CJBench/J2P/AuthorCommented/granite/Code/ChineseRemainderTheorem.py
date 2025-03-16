

import sys

def solveCRT(remainders, moduli):
    product = 1
    result = 0

    # Calculate the product of all moduli
    for mod in moduli:
        product *= mod

    # Apply the formula for each congruence
    for i in range(len(moduli)):
        partialProduct = product // moduli[i]
        inverse = modInverse(partialProduct, moduli[i])
        result += remainders[i] * partialProduct * inverse

    # Adjust result to be the smallest positive solution
    result = result % product
    if result < 0:
        result += product

    return result

def modInverse(a, m):
    m0 = m
    x0 = 0
    x1 = 1

    if m == 1:
        return 0

    while a > 1:
        q = a // m
        t = m

        # m is remainder now, process same as Euclid's algorithm
        m = a % m
        a = t
        t = x0

        x0 = x1 - q * x0
        x1 = t

    # Make x1 positive
    if x1 < 0:
        x1 += m0

    return x1

if __name__ == "__main__":
    # Read the number of congruences
    n = int(input())

    # Read the remainders and moduli
    remainders = []
    moduli = []
    for i in range(n):
        remainder, modulus = map(int, input().split())
        remainders.append(remainder)
        moduli.append(modulus)

    # Solve using CRT
    solution = solveCRT(remainders, moduli)
    print("Smallest positive solution:", solution)

