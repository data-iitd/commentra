
# Function to read the input DNA sequence from the standard input
def read_input():
	# Read the input DNA sequence from the standard input using input() function
	s = input()

	# Return the input DNA sequence
	return s

# Function to count the number of nucleotides in the input DNA sequence
def count_nucleotides(s):
	# Initialize a counter variable to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
	count = 0

	# Iterate through each nucleotide in the input DNA sequence using a for loop
	for s in s:
		# Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
		if s == "A" or s == "C" or s == "G" or s == "T":
			# If the current nucleotide is a valid nucleotide, increment the 'count' variable
			count += 1

	# Return the count of nucleotides in the input DNA sequence
	return count

# Function to split the input DNA sequence into a slice of individual nucleotides
def split_nucleotides(s):
	# Split the input DNA sequence into a slice 'li' of individual nucleotides using split() function
	li = s.split("")

	# Return the slice 'li' of individual nucleotides
	return li

# Function to sort the slice of individual nucleotides in ascending order
def sort_nucleotides(li):
	# Sort the 'li' slice of individual nucleotides in ascending order using sort() function
	li.sort()

	# Return the sorted 'li' slice of individual nucleotides
	return li

# Function to find the maximum count of nucleotides in any sub-sequence
def find_max_count(li):
	# Initialize a counter variable to keep track of the maximum count of nucleotides in any sub-sequence
	max_count = 0

	# Iterate through each nucleotide in the 'li' slice of individual nucleotides using a for loop
	for s in li:
		# Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
		if s == "A" or s == "C" or s == "G" or s == "T":
			# If the current nucleotide is a valid nucleotide, increment the'max_count' variable
			max_count += 1

	# Return the maximum count of nucleotides in any sub-sequence
	return max_count

# Function to print the maximum count of nucleotides in any sub-sequence
def print_max_count(max_count):
	# Print the maximum count of nucleotides in any sub-sequence
	print(max_count)

# Main function
def main():
	# Read the input DNA sequence from the standard input
	s = read_input()

	# Check if the input DNA sequence is empty or not
	if s == "":
		# If the input DNA sequence is empty, return without doing anything
		return

	# Count the number of nucleotides in the input DNA sequence
	count = count_nucleotides(s)

	# Split the input DNA sequence into a slice of individual nucleotides
	li = split_nucleotides(s)

	# Sort the slice of individual nucleotides in ascending order
	li = sort_nucleotides(li)

	# Find the maximum count of nucleotides in any sub-sequence
	max_count = find_max_count(li)

	# Print the maximum count of nucleotides in any sub-sequence
	print_max_count(max_count)

# Call the main function
if __name__ == "__main__":
	main()

# 