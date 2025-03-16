n = int(input())  # Read the number of strings from the standard input

# Initialize a list to store the count of each character
cnt = [1] * 26  # Start with 1 for each character

# Read the strings from the standard input and update the count list accordingly
for _ in range(n):
    s = input()  # Read a string from the standard input
    cnt[ord(s[0]) - ord('a')] += 1  # Increment the count of the character

# Calculate the answer using the count list
ans = 1  # Initialize the answer to 1
for i in range(26):  # Iterate through all the characters from 'a' to 'z'
    ans *= cnt[i]  # Multiply the answer with the count of the current character

# Calculate the final answer by subtracting 1 from the initial answer
ans -= 1

# Print the final answer to the standard output
print(ans)

# Indicate the successful termination of the program
# <END-OF-CODE>
