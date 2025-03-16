
# Declare a string variable to store the input
a = input()

# Initialize the variable `ans` with the value "Good"
ans = "Good"

# Loop through the first three characters of the string `a`
for i in range(3):
    # Check if the current character is the same as the next character
    if a[i] == a[i+1]:
        # If the condition is true, change the value of `ans` to "Bad"
        ans = "Bad"

# Print the value of `ans`
print(ans)

