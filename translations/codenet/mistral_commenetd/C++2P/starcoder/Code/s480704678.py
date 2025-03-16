
# Read the number of elements in the array 'a'
n = int(input())

# Initialize a vector 'a' of size 'n'
a = [0] * n

# Initialize a vector 'acc' of size 'n+1' with zero as initial value
acc = [0] * (n + 1)

# Read the elements of the array 'a' and calculate the cumulative sum
for i in range(n):
  a[i] = int(input())
  acc[i + 1] = acc[i] + a[i]
  acc[i + 1] %= MOD

# Initialize the answer 'ans' to zero
ans = 0

# Calculate the answer using the formula
for i in range(n):
  # Calculate the contribution of the current element 'a[i]' to the answer
  temp = a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD

  # Add the contribution to the answer
  ans += temp
  ans %= MOD

# Print the answer
print(ans)

