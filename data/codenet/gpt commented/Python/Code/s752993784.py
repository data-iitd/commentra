# Read input as a list of characters
s = list(input())

# Initialize a list to store the count of occurrences of each remainder when divided by 2019
countRemainder = [0] * 2019

# Initialize a counter for the number of valid pairs
cnt = 0

# Initialize variables for calculating the modulus
m = 1  # Multiplier for the current digit's place value
mod = 0  # Current modulus value

# Iterate through the input string in reverse order
for i in range(len(s)):
    # Update the modulus by adding the current digit multiplied by its place value
    mod += int(s[len(s) - i - 1]) * m

    # Take modulus 2019 to keep the value manageable
    mod %= 2019

    # Update the multiplier for the next digit's place value
    m *= 10
    m %= 2019  # Again, take modulus to avoid overflow

    # Increment the count of the current modulus in the countRemainder list
    countRemainder[mod] += 1

# Account for the case where the modulus is 0
countRemainder[0] += 1

# Calculate the number of valid pairs of indices that yield the same modulus
for i in range(2019):
    # Use the combination formula to count pairs from the occurrences of each modulus
    cnt += int(countRemainder[i] * (countRemainder[i] - 1) / 2)

# Print the total count of valid pairs
print(cnt)
