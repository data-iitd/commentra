# Read two integer values from the standard input
A, B = map(int, input().split())

# Calculate the result based on the value of A
if 6 <= A <= 12:
    ans = B // 2
elif A > 12:
    ans = B
else:
    ans = 0  # Default case if A is less than 6

# Print the result
print(ans)

# <END-OF-CODE>