import math

def solve_crt(remainders, moduli):
    product = 1
    result = 0

    # Calculate the product of all moduli
    for mod in moduli:
        product *= mod

    # Calculate the result using the CRT formula
    for i in range(len(moduli)):
        partial_product = product // moduli[i]
        inverse = mod_inverse(partial_product, moduli[i])
        result += remainders[i] * partial_product * inverse

    # Apply modulo to ensure the result is within the range of the product
    result = result % product
    if result < 0:
        result += product
    return result

def mod_inverse(a, m):
    m0 = m
    x0 = 0
    x1 = 1

    # If m is 1, the inverse is 0
    if m == 1:
        return 0

    # Apply the Extended Euclidean Algorithm
    while a > 1:
        q = a // m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t

    # Ensure x1 is positive
    if x1 < 0:
        x1 += m0
    return x1

def main():
    n = int(input())
    remainders = []
    moduli = []

    # Read each remainder and modulus pair
    for i in range(n):
        remainder = int(input())
        modulus = int(input())
        remainders.append(remainder)
        moduli.append(modulus)

    # Solve the CRT and print the smallest positive solution
    solution = solve_crt(remainders, moduli)
    print("Smallest positive solution:", solution)

if __name__ == "__main__":
    main()

