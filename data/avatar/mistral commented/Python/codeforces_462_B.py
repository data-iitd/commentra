#######
# Code
#######

# Define input variables
n, k = map(int, input().split())
# n: number of characters in the string s
# k: number of occurrences of a character we want to find

s = input()
# s: string to be processed

# Initialize a list to store the count of each character
count = [0] * 26

# Iterate through each character in the string s
for c in s:
    # Increment the count of the character in the list count
    count[ord(c) - ord("A")] += 1

# Sort the count list in descending order
count.sort(reverse=True)

# Initialize result variable
res = 0

# Iterate through each character count in the list count
for i in range(26):
    # Check if the count of the current character is greater than or equal to k
    if count[i] >= k:
        # Calculate the result and print it
        res += k * k
        print(res)
        # Exit the loop as we have found the required characters
        exit()
    # Update the value of k by subtracting the count of the current character
    k -= count[i]
    # Add the square of the count of the current character to the result
    res += count[i] ** 2

# Print the final result if no character is found with the required count
print(res)
