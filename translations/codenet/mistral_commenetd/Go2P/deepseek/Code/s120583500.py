def main():
    # Read the input DNA sequence from the standard input using input() function
    s = input()

    # Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
    # and a list 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
    count = 0
    counter = []

    # Check if the input DNA sequence is empty or not
    if not s:
        # If the input DNA sequence is empty, return without doing anything
        return

    # Split the input DNA sequence into a list 'li' of individual nucleotides using list comprehension
    li = [char for char in s if char in "ACGT"]

    # Iterate through each nucleotide in the 'li' list using a for loop
    for char in li:
        # If the current nucleotide is a valid nucleotide (A, C, G, T), increment the 'count' variable
        if char in "ACGT":
            count += 1
        else:
            # If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' list and reset the 'count' variable to 0
            counter.append(count)
            count = 0

    # Append the final count of nucleotides in the last sub-sequence to the 'counter' list
    counter.append(count)

    # Print the maximum count of nucleotides in any sub-sequence
    print(max(counter))

# Call the main function
main()
