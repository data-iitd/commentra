
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Read the integer N (length of the string) and K (number of changes allowed)
N = sc.nextInt()
K = sc.nextInt()

# Read the string S
S = sc.next()

# Convert the string S into a character array for manipulation
c1 = list(S)
c3 = list(S)

# Initialize a flag to track changes and a count for 'R' occurrences
flag = False
count = 0

# First pass: Change 'L' to 'R' up to K times
for i in range(N):
    # If the flag is set and the current character is 'R', increment count and reset flag
    if flag and c1[i] == 'R':
        flag = False
        count += 1
    # Break the loop if K changes have been made
    if count == K:
        break
    # If the current character is 'L', set the flag and change 'L' to 'R'
    if c1[i] == 'L':
        flag = True
        c1[i] = 'R'

# Reset flag and count for the second pass
flag = False
count = 0

# Second pass: Change 'R' to 'L' up to K times
for i in range(N):
    # If the flag is set and the current character is 'L', increment count and reset flag
    if flag and c3[i] == 'L':
        flag = False
        count += 1
    # Break the loop if K changes have been made
    if count == K:
        break
    # If the current character is 'R', set the flag and change 'R' to 'L'
    if c3[i] == 'R':
        flag = True
        c3[i] = 'L'

# Convert the modified character arrays back to strings
S1 = ''.join(c1)
S3 = ''.join(c3)

# Initialize variables to count consecutive characters in S1
count = 1
sum1 = 0
bef = S1[0]

# Count the number of consecutive characters in S1
for i in range(1, N):
    if S1[i] == bef:
        count += 1
        # If it's the last character, add the count to sum1
        if i == N - 1:
            sum1 += count - 1
    else:
        bef = S1[i]
        sum1 += count - 1
        count = 1

# Reset count and initialize variables to count consecutive characters in S3
count = 1
sum3 = 0
bef = S3[0]

# Count the number of consecutive characters in S3
for i in range(1, N):
    if S3[i] == bef:
        count += 1
        # If it's the last character, add the count to sum3
        if i == N - 1:
            sum3 += count - 1
    else:
        bef = S3[i]
        sum3 += count - 1
        count = 1

# Output the maximum of the two sums calculated from S1 and S3
print(max(sum1, sum3))

