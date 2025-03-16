
# Declare a variable to hold the input string
s = input()

# Initialize the answer variable with "No"
ans = "No"

# Check if the first occurrence of 'C' is before the last occurrence of 'F'
if s.find("C") < s.rfind("F"):
    # If true, set the answer to "Yes"
    ans = "Yes"

# Check if 'C' does not exist in the string
if s.find("C") < 0:
    # If true, set the answer to "No"
    ans = "No"

# Print the final answer
print(ans)

