

import sys
import math

# Taking input from the user
n = int(input("Enter the number of elements in the array: "))
A = list(map(int, input("Enter the elements of the array separated by spaces: ").split()))

# Modulus constant for efficient modular arithmetic
div = 10**9 + 7

# Initializing the answer variable to zero
ans = 0

# Looping through all the bits from 0 to 59
for i in range(60):
 a = 0
 count1 = 0

 # Counting the number of elements in the array A with the i-th bit set to 1
 for j in range(n):
 if (A[j] >> i) & 1:
 count1 += 1

 # Calculating the contribution of the i-th bit to the answer
 a += count1 * (n - count1)

 # Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for j in range(i):
 a = (a << 1) % div

 # Adding the contribution to the answer
 ans += a
 ans %= div

# Printing the answer
print("The answer is:", ans)

