# Declare two integer variables A and B
A, B = map(int, input().split())

# Declare a variable to store the result
ans = 0

# Check if A is between 6 and 12 inclusive
if 6 <= A <= 12:
    # Calculate the half of B and assign it to ans
    ans = B // 2
elif A > 12:
    # Assign B to ans if A is greater than 12
    ans = B

# Print the value of ans
print(ans)

# <END-OF-CODE>
