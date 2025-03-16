# Read the values of N and A from the standard input
N, A = map(int, input().split())

# Use the conditional expression to check if the remainder of N divided by 500 is less than or equal to A
print("Yes" if N % 500 <= A else "No")

# End of the code
# <END-OF-CODE>
