s = input()  # Read a string from standard input

ans = "No"  # Initialize the answer variable with "No"

# Check if 'C' appears before the last occurrence of 'F' in the string s
if s.find("C") < s.rfind("F"):
    ans = "Yes"  # Update ans to "Yes" if the condition is true

# Check if 'C' does not appear in the string s
if s.find("C") < 0:
    ans = "No"  # Update ans to "No" if the condition is true

print(ans)  # Print the final value of ans
# <END-OF-CODE>
