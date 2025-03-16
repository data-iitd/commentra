# Initialize an empty list to store the input string as a list of characters
s = list(input())

# Initialize a list of zeros of length equal to the length of the input string
# This list will be used to store the running modulus at each position in the input string
mods = [0]*(len(s))

# Initialize a list of zeros of length 2019 to store the count of remainders at each index
countRemainder = [0] * 2019

# Initialize a counter variable to store the final result
cnt = 0

# Set the base value of the modulus to 1
m = 1

# Set the initial value of the modulus to 0
mod = 0

# Iterate through each character in the input string from right to left
for i in range(len(s)):
    # Calculate the current digit's contribution to the modulus
    digit = int(s[len(s) - i - 1])

    # Update the modulus by adding the digit's contribution multiplied by the current power of 10
    mod += digit * m

    # Update the modulus by taking the remainder of the modulus with the modulus value (2019)
    mod %= 2019

    # Update the power of 10 for the next digit by taking the remainder of the power with the modulus value (2019)
    m *= 10
    m %= 2019

    # Increment the count of remainders at the current index in the countRemainder list
    countRemainder[mod] += 1

# Increment the count of zeros (index 0) in the countRemainder list
countRemainder[0] += 1

# Calculate the final result by summing up the number of combinations of distinct remainders
for i in range(2019):
    # Calculate the number of combinations of distinct remainders at index i in the countRemainder list
    cnt += int(countRemainder[i] * (countRemainder[i] - 1) / 2)

# Print the final result
print(cnt)
