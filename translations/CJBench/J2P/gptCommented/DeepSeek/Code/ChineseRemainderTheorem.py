def solve_crt(remainders, moduli):
    product = 1
    result = 0

    # Calculate the product of all moduli
    for mod in moduli:
        product *= mod

    # Calculate the result using the CRT formula
    for i in range(len(moduli)):
        partial_product = product // moduli[i]  # Calculate the partial product
        inverse = mod_inverse(partial_product, moduli[i])  # Find the modular inverse
        result += remainders[i] * partial_product * inverse  # Update the result

    # Apply modulo to ensure the result is within the range of the product
    result = result % product
    if result < 0:
        result += product  # Adjust result if it's negative

    return result  # Return the final result


def mod_inverse(a, m):
    m0 = m
    x0, x1 = 0, 1

    # If m is 1, the inverse is 0
    if m == 1:
        return 0

    # Apply the Extended Euclidean Algorithm
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0

    # Ensure x1 is positive
    if x1 < 0:
        x1 += m0

    return x1  # Return the modular inverse


# Main function to execute the program
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])  # Read the number of equations
    remainders = []  # List to store remainders
    moduli = []  # List to store moduli

    # Read each remainder and modulus pair
    for i in range(1, n + 1):
        remainder = int(data[i])
        modulus = int(data[i + n])
        remainders.append(remainder)
        moduli.append(modulus)

    # Solve the CRT and print the smallest positive solution
    solution = solve_crt(remainders, moduli)
    print("Smallest positive solution:", solution)


if __name__ == "__main__":
    main()
