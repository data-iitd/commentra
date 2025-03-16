# Declare variables N and D, which are integers between 1 and 20
N, D = map(int, input().split())  # Read two integers from standard input

# Calculate the number of complete groups of size (D*2 + 1) that can be formed from N
ans = N // (D * 2 + 1)
# Calculate the remainder when N is divided by (D*2 + 1)
rem = N % (D * 2 + 1)

# If there is a remainder, it means we need one additional group
if rem != 0:
    ans += 1  # Increment the answer by 1

# Output the final answer
print(ans)

# <END-OF-CODE>
