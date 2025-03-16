
# Function main is the entry point of the program
def main():
	# Initialize an integer slice named in with a length of 3
	in = [0] * 3

	# Use fmt.Scan to read three integers from the standard input and store them in the slice in
	in[0], in[1], in[2] = map(int, input().split())

	# Sort the integers in ascending order using sort.Ints function
	in.sort()

	# Multiply the last integer by 10 and add the second last and the last integer
	# Then print the result using fmt.Println
	print(in[2] * 10 + in[1] + in[0])

# 