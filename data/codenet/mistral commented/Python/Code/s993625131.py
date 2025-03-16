# Initialize an empty list to store the input string
S = list(input())

# Initialize two variables: count to keep track of the number of nucleotides in a row, and record to keep track of the longest consecutive sequence of nucleotides
count = 0
record = 0

# Iterate through each character in the list
for i in range(len(S)):
    # If the character is a nucleotide (A, C, G, T), we increment the count variable
    if S[i] in ["A", "C", "G", "T"]:
        count += 1
    # If the character is not a nucleotide, we check if the current count is greater than the record. If it is, we update the record variable with the new value of count. We also reset the count variable to 0.
    else:
        if count > record:
            record = count
        count = 0

# Check one last time if the final value of count is greater than the record. If it is, we update the record variable with the new value of count.
if count > record:
    record = count

# Print out the value of record
print(record)
