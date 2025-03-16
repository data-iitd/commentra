# Declare a variable to hold the input string
a = input()

# Initialize a variable 'ans' with the default value "Good"
ans = "Good"

# Loop through the first three characters of the string 'a'
for i in range(3):
    # Check if the current character is the same as the next character
    if a[i] == a[i + 1]:
        # If they are the same, set 'ans' to "Bad"
        ans = "Bad"

# Print the final result stored in 'ans'
print(ans)

# <END-OF-CODE>
