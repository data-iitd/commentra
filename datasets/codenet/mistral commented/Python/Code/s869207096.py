# Take an integer input from the user and assign it to the variable n
n = int(input())

# Take a string input from the user and assign it to the variable s
s = input()

# Initialize the variable cnt to 1
cnt = 1

# Iterate through all indices of the string s except the last one
for i in range(n - 1):
    # Check if the character at the current index i is equal to the character at the next index i+1
    if s[i] == s[i + 1]:
        # If they are equal, then skip the rest of the loop and move on to the next iteration
        continue

    # If they are not equal, then increment the variable cnt by 1
    else:
        cnt += 1

# Print the final count to the console
print(cnt)