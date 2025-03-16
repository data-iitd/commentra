# Read input string and convert it to a list of characters
S = list(input())

# Initialize counters for the current sequence length and the maximum recorded length
count = 0
record = 0

# Iterate through each character in the list
for i in range(len(S)):
    # Check if the character is one of the valid nucleotides (A, C, G, T)
    if S[i] == "A" or S[i] == "C" or S[i] == "G" or S[i] == "T":
        # Increment the count for the current valid nucleotide sequence
        count += 1
    else:
        # If the current sequence ends, check if it's the longest one recorded
        if count > record:
            record = count  # Update the record if the current count is greater
        # Reset the count for the next sequence
        count = 0

# Final check to update the record in case the longest sequence ends at the last character
if count > record:
    record = count

# Print the length of the longest valid nucleotide sequence found
print(record)
