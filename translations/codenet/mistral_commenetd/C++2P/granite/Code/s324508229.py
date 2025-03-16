

# Python code

# Read the number of test cases
n = int(input())

# Initialize a 10x10 2D array 'cnt' with zeroes
cnt = [[0 for i in range(10)] for j in range(10)]

# Iterate through each number from 1 to n
for i in range(1, n+1):
    # Extract the last digit 'b' and the digit before last 'a' from the number 'i'
    b = i % 10
    a = i
    while a >= 10:
        a //= 10

    # Increment the count of 'a'th row and 'b'th column in the 'cnt' array
    cnt[a-1][b-1] += 1

# Initialize answer variable 'ans' with zero
ans = 0

# Iterate through each row and column from 1 to 9
for i in range(10):
    for j in range(10):
        # Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
        # and add it to the answer
        ans += cnt[i][j] * cnt[j][i]

# Print the final answer
print(ans)

