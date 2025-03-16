# Declare integer variables to store user input and the result
a, b = map(int, input().split())

# Initialize the result variable to 0
ans = 0

# Check the value of 'a' and update 'ans' accordingly
if a >= 13:
    # If 'a' is 13 or greater, set 'ans' to 'b'
    ans = b
elif a >= 6:
    # If 'a' is between 6 and 12 (inclusive), set 'ans' to half of 'b'
    ans = b // 2

# Print the result
print(ans)

# <END-OF-CODE>
