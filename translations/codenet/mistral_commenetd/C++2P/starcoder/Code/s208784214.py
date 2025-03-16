
# Define two integer variables: N and A
N, A = int(input()), int(input())

# Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
print("Yes" if N % 500 <= A else "No")

# End the main function and return 0 to indicate successful execution
return 0

