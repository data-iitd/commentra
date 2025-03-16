
# Declare a string variable named'str' to store the input string
str = input()

# Initialize two integer variables'max' and 'cnt' with zero values
max = 0
cnt = 0

# Iterate through each character in the input string using a range-based for loop
for sc in str:
    # Check if the current character is a valid nucleotide (A, C, G or T)
    if sc == 'A' or sc == 'C' or sc == 'G' or sc == 'T':
        cnt += 1 # Increment the count if the character is a valid nucleotide
    else: # Otherwise, reset the count to zero
        cnt = 0

    # Update the maximum count if the current count is greater than the previous maximum
    max = max < cnt and cnt or max

# Print the maximum count of valid nucleotides found in the input string
print(max)

