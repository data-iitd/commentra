
import math
N,K = (int(x) for x in input().split())
R = N - K
mod = 10**9 + 7

# Function to compute binomial coefficient using factorials
def fact(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

# Loop to calculate and print the result for each i from 1 to K
for i in range(1,K+1):
  if N - K + 1 < i:
    ans = 0
  else:
    # Calculate ans using the fact function for two different combinations
    ans = fact(R+1, i)*fact(K-1,i-1)
  print(int(ans)%mod)

