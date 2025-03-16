#######
# Code
#######

# Initialize the number of test cases
n = int(input())

# Initialize a list 'l' of size 1000010 with zeros
l = [0 for _ in range(1000010)]

# Initialize a list 'dp' of size 1000010 with zeros
dp = [0 for _ in range(1000010)]

# Read input for 'n' test cases
for i in range(n):
    # Read two integers 'a' and 'b' as input
    a, b = map(int, input().split())
    # Assign value 'b' to index 'a' in list 'l'
    l[a] = b

# Check if the first element of the list 'l' is positive
if l[0] > 0:
    # Set the first element of 'dp' to 1
    dp[0] = 1

# Initialize a variable 'mx' to keep track of the maximum length of a subsequence
mx = 0

# Iterate through the list 'l' from index 1 to 1000010
for i in range(1, 1000010):
    # If the current element of 'l' is zero, set the corresponding element of 'dp' to the previous element
    if l[i] == 0:
        dp[i] = dp[i - 1]
    # If the current element of 'l' is greater than or equal to 'i', set the corresponding element of 'dp' to 1
    # This indicates that the current element is part of a subsequence of length 'i'
    elif l[i] >= i:
        dp[i] = 1
    # If the current element of 'l' is less than 'i', calculate the length of the longest subsequence ending at 'i - l[i] - 1'
    # and add 1 to get the length of the subsequence ending at 'i'
    else:
        dp[i] = dp[i - l[i] - 1] + 1
    # Update the maximum length of a subsequence if a longer one is found
    if dp[i] > mx:
        mx = dp[i]

# Print the answer, which is the number of elements in the longest subsequence that is not a subsequence of the given sequence
print(n - mx)
