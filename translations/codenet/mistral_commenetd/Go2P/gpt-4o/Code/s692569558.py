# Import necessary modules
import sys

def main():
    # Read the first two lines from standard input
    input()  # Read and ignore the first line
    ds = input()  # Read the second line

    # Split the string ds into a list of strings dd
    dd = ds.split()

    # Convert the list of strings dd into a list of integers dn
    dn = [int(d) for d in dd]

    # Initialize sum variable to 0
    sum = 0

    # Iterate through each index i in the list dn
    for i in range(len(dn)):
        # Iterate through each index j greater than i in the list dn
        for j in range(i + 1, len(dn)):
            # Add the product of dn[i] and dn[j] to the sum variable
            sum += dn[i] * dn[j]

    # Print the value of sum variable to the standard output
    print(sum)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
