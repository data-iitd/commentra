

# Python code

# Read the number of elements in the array 'a'
n = int(input())

# Initialize a list 'a' of size 'n'
a = [int(input()) for _ in range(n)]

# Initialize a list 'acc' of size 'n+1' with zero as initial value
acc = [0] * (n + 1)

# Read the elements of the array 'a' and calculate the cumulative sum
for i in range(n):
  acc[i + 1] = (acc[i] + a[i]) % 1000000007

# Initialize the answer 'ans' to zero
ans = 0

# Calculate the answer using the formula
for i in range(n):
  # Calculate the contribution of the current element 'a[i]' to the answer
  temp = a[i] * (1000000007 + acc[n] - acc[i + 1]) % 1000000007
  # Add the contribution to the answer
  ans += temp
  # Perform modulo operation to keep the value within the range of 'MOD'
  ans %= 1000000007

# Print the answer
print(ans)

