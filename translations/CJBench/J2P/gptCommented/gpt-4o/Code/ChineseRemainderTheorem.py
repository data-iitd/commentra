from typing import List

class Main:
    @staticmethod
    def solve_crt(remainders: List[int], moduli: List[int]) -> int:
        product = 1  # Variable to store the product of all moduli
        result = 0   # Variable to accumulate the result

        # Calculate the product of all moduli
        for mod in moduli:
            product *= mod

        # Calculate the result using the CRT formula
        for i in range(len(moduli)):
            partial_product = product // moduli[i]  # Calculate the partial product
            inverse = Main.mod_inverse(partial_product, moduli[i])  # Find the modular inverse
            result += remainders[i] * partial_product * inverse  # Update the result

        # Apply modulo to ensure the result is within the range of the product
        result = result % product
        if result < 0:
            result += product  # Adjust result if it's negative
        return result  # Return the final result

    @staticmethod
    def mod_inverse(a: int, m: int) -> int:
        m0 = m  # Store the original modulus
        x0 = 0  # Initialize x0
        x1 = 1  # Initialize x1

        # If m is 1, the inverse is 0
        if m == 1:
            return 0

        # Apply the Extended Euclidean Algorithm
        while a > 1:
            q = a // m  # Calculate quotient
            t = m  # Store current modulus
            m = a % m  # Update modulus
            a = t  # Update a
            t = x0  # Store current x0
            x0 = x1 - q * x0  # Update x0
            x1 = t  # Update x1

        # Ensure x1 is positive
        if x1 < 0:
            x1 += m0
        return x1  # Return the modular inverse

# Main execution
if __name__ == "__main__":
    n = int(input("Enter the number of equations: "))  # Read the number of equations
    remainders = []  # List to store remainders
    moduli = []  # List to store moduli

    # Read each remainder and modulus pair
    for _ in range(n):
        remainder, modulus = map(int, input("Enter remainder and modulus: ").split())  # Read remainder and modulus
        remainders.append(remainder)  # Add remainder to the list
        moduli.append(modulus)  # Add modulus to the list

    # Solve the CRT and print the smallest positive solution
    solution = Main.solve_crt(remainders, moduli)
    print("Smallest positive solution:", solution)

# <END-OF-CODE>
