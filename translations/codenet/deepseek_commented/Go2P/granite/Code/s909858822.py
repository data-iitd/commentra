
# Declare two integer variables A and B
A = int(input())
B = int(input())

# Declare a variable to store the result
ans = 0

# Check if A is between 6 and 12 inclusive
if 6 <= A <= 12:
    # Calculate the half of B and assign it to ans
    ans = B // 2
elif 12 < A:
    # Assign B to ans if A is greater than 12
    ans = B

# Print the value of ans
print(ans)

