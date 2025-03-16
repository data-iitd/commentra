
S = list(input())  # Take input string and convert it to a list of characters

count = 0  # Initialize a counter for consecutive 'A', 'C', 'G', or 'T' characters
record = 0  # Initialize a variable to keep track of the maximum sequence length

# Iterate over each character in the string S
for i in range(len(S)):
    if S[i] == "A" or S[i] == "C" or S[i] == "G" or S[i] == "T":  # Check if the character is 'A', 'C', 'G', or 'T'
        count += 1  # Increment the count if the character matches
    else:
        if count > record:  # Check if the current count is greater than the record
            record = count  # Update the record if necessary
        count = 0  # Reset the count to 0 for the next sequence

if count > record:  # Check if the final count is greater than the record
    record = count  # Update the record if necessary

print(record)  # Print the maximum sequence length found

