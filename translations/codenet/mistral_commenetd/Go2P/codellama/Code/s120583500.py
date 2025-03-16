
# Import the required modules
import sys

# Function main is the entry point of the program
def main():
    # Initialize an empty string variable 's' to store the input DNA sequence
    s = ""

    # Read the input DNA sequence from the standard input using sys.stdin.readline() function
    s = sys.stdin.readline().strip()

    # Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
    # and a list 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
    count = 0
    counter = []

    # Check if the input DNA sequence is empty or not
    if s == "":
        # If the input DNA sequence is empty, return without doing anything
        return

    # Initialize the first element of the 'counter' list with an initial count of 0
    counter.append(0)

    # Split the input DNA sequence into a list 'li' of individual nucleotides using s.split() function
    li = s.split()

    # Iterate through each nucleotide in the 'li' list using a for loop
    for s in li:
        # Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
        if s == "A" or s == "C" or s == "G" or s == "T":
            # If the current nucleotide is a valid nucleotide, increment the 'count' variable
            count += 1
        else:
            # If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' list and reset the 'count' variable to 0
            counter.append(count)
            count = 0

    # Append the final count of nucleotides in the last sub-sequence to the 'counter' list
    counter.append(count)

    # Sort the 'counter' list in ascending order using sorted() function
    counter = sorted(counter)

    # Print the last element of the sorted 'counter' list, which represents the maximum count of nucleotides in any sub-sequence
    print(counter[len(counter)-1])

# Call the main function
main()

