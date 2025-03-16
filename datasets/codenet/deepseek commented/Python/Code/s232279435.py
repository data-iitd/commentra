
n = int(input())  # Read the integer input for the length of the string
s = str(input())  # Read the string input

ans = 0  # Initialize the answer variable to 0

for i in range(n):  # Loop through each index of the string
    x = set(s[:i+1])  # Create a set of characters from the start of the string to the current index
    y = set(s[i+1:])  # Create a set of characters from the current index to the end of the string

    z = 0  # Initialize a variable to count the number of common characters
    for w in x:  # Loop through each character in set x
        if w in y:  # Check if the character is in set y
            z += 1  # Increment the count if the character is common
    if z > ans:  # Check if the count of common characters is greater than the current answer
        ans = z  # Update the answer if a new maximum is found
print(ans)  # Print the final answer

