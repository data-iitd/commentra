# Importing necessary modules
import sys

def main():
    # Read the first line of input (not used)
    input()  # Read and ignore the first line
    # Read the second line of input which contains space-separated integers
    ds = input().strip()

    # Split the input string into a list of strings
    dd = ds.split()
    # Create a list of integers to hold the converted values
    dn = [int(d) for d in dd]  # Convert each string in the list to an integer

    # Initialize a variable to hold the sum of products
    sum_products = 0
    # Calculate the sum of products of all unique pairs of integers
    for i in range(len(dn)):
        for j in range(i + 1, len(dn)):
            sum_products += dn[i] * dn[j]  # Multiply the pair and add to sum

    # Output the final sum of products
    print(sum_products)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
