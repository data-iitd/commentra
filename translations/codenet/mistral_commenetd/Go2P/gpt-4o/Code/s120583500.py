# Import necessary modules
import sys

# Function main is the entry point of the program
def main():
    # Read the input DNA sequence from the standard input
    s = input().strip()

    # Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T)
    count = 0
    counter = []

    # Check if the input DNA sequence is empty or not
    if s == "":
        return

    # Iterate through each character in the input string
    for nucleotide in s:
        # Check if the current character is a valid nucleotide (A, C, G, T)
        if nucleotide in "ACGT":
            # If valid, increment the count
            count += 1
        else:
            # If not valid, append the current count to the counter list and reset count
            counter.append(count)
            count = 0

    # Append the final count of nucleotides in the last sub-sequence to the counter list
    counter.append(count)

    # Sort the counter list in ascending order
    counter.sort()

    # Print the last element of the sorted counter list, which represents the maximum count
    print(counter[-1])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
