
s = list(input())  # Convert input string to a list of characters
mods = [0]*(len(s))  # Initialize a list to store remainders
countRemainder = [0] * 2019  # Initialize a list to count occurrences of each remainder
cnt = 0  # Initialize a counter for valid pairs

m = 1  # Initialize multiplier for calculating the modulus
mod = 0  # Initialize the current modulus
for i in range(len(s)):  # Iterate over the string in reverse order
    mod += int(s[len(s) - i - 1]) * m  # Update the current modulus
    mod %= 2019  # Calculate the modulus modulo 2019
    m *= 10  # Update the multiplier for the next digit
    m %= 2019  # Ensure the multiplier does not overflow
    countRemainder[mod] += 1  # Increment the count for the current modulus

countRemainder[0] += 1  # Increment the count for modulus 0

for i in range(2019):  # Calculate the number of valid pairs
    cnt += int(countRemainder[i] * (countRemainder[i] - 1) / 2)  # Use the formula for combinations

print(cnt)  # Print the final count of valid pairs

