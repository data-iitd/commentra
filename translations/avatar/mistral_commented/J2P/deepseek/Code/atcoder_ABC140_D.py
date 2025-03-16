import sys

# Read input from standard input
N = int(input().split()[0])
K = int(input().split()[1])
S = input().strip()

# Convert the string to a list of characters
c1 = list(S)
c3 = list(S)

# Process the first character array c1
flag1 = False
count1 = 0
for i in range(N):
    if flag1 and c1[i] == 'R':
        flag1 = False
        count1 += 1
    if count1 == K:
        break
    if c1[i] == 'L':
        flag1 = True

# Process the second character array c3
flag3 = False
count3 = 0
for i in range(N):
    if flag3 and c3[i] == 'L':
        flag3 = False
        count3 += 1
    if count3 == K:
        break
    if c3[i] == 'R':
        flag3 = True

# Create new strings from the character arrays
S1 = ''.join(c1)
S3 = ''.join(c3)

# Find the length of the longest consecutive identical characters in S1
count2 = 1
sum1 = 0
bef1 = S1[0]
for i in range(1, N):
    if S1[i] == bef1:
        count2 += 1
    else:
        sum1 += count2 - 1
        count2 = 1
        bef1 = S1[i]
sum1 += count2 - 1

# Find the length of the longest consecutive identical characters in S3
count4 = 1
sum3 = 0
bef3 = S3[0]
for i in range(1, N):
    if S3[i] == bef3:
        count4 += 1
    else:
        sum3 += count4 - 1
        count4 = 1
        bef3 = S3[i]
sum3 += count4 - 1

# Print the maximum of sum1 and sum3
print(max(sum1, sum3))
