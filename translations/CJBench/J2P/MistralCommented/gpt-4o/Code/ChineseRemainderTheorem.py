from typing import List

def mod_inverse(a: int, m: int) -> int:
    # Function to calculate the modular inverse of 'a' with respect to 'm'
    m0, x0, x1 = m, 0, 1

    if m == 1:
        return 0

    while a > 1:
        q = a // m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t

    if x1 < 0:
        x1 += m0

    return x1

def solve_crt(remainders: List[int], moduli: List[int]) -> int:
    # Function to solve the Chinese Remainder Theorem problem
    product = 1
    result = 0

    for mod in moduli:
        product *= mod

    for i in range(len(moduli)):
        partial_product = product // moduli[i]
        inverse = mod_inverse(partial_product, moduli[i])
        result += remainders[i] * partial_product * inverse

    result = result % product

    if result < 0:
        result += product

    return result

def main():
    # Main function to read input and call the solve_crt function
    n = int(input("Enter the number of pairs (remainder, modulus): "))  # Read the number of pairs

    remainders = []  # Initialize an empty list to store remainders
    moduli = []     # Initialize an empty list to store moduli

    for _ in range(n):
        # Read each pair (remainder, modulus) and add them to the respective lists
        remainder, modulus = map(int, input("Enter remainder and modulus: ").split())
        remainders.append(remainder)
        moduli.append(modulus)

    solution = solve_crt(remainders, moduli)  # Call the solve_crt function to find the solution

    print("Smallest positive solution:", solution)  # Print the solution to the console

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
