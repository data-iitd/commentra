import sys

# Create a BufferedReader to read input from the standard input stream
br = sys.stdin

# Create a PrintWriter to output results to the standard output stream
pw = sys.stdout

# Read a line of input, split it into an array of strings based on spaces
input_array = br.readline().split()

# Initialize a counter to keep track of the number of non-zero inputs
result = 0

# Iterate through each string in the input array
for str in input_array:
    # Increment the counter for each input
    result += 1
    
    # If the input is "0", break out of the loop
    if str == "0":
        break

# Print the result, which is the count of non-zero inputs before the first "0"
pw.write(str(result) + "\n")

# Close the BufferedReader to free up resources
br.close()

# Close the PrintWriter to ensure all output is flushed and resources are freed
pw.close()

# END-OF-CODE
