
# Declare a string variable 'a' to store user input
a = input()

# Initialize a string variable 'ans' with value "Good"
ans = "Good"

# Loop through each character in the string 'a' for 3 times
for i in range(3):
    # Check if the current character is same as next character
    if a[i] == a[i+1]:
        # Update the value of 'ans' if current and next character are same
        ans = "Bad"

# Print the final value of 'ans'
print(ans)

