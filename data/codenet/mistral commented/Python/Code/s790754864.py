# Importing the math module for using mathematical functions like factorial
import math

# Taking the number of test cases and the number of students in each test as input
N, K = (int(x) for x in input().split())

# Calculating the number of extra students required to make the total number of students equal to the number of tests
R = N - K

# Defining a function 'fact' to calculate the binomial coefficient using mathematical factorials
def fact(n, r):
    # Calculating the mathematical factorial of 'n'
    return math.factorial(n)

    # Calculating the mathematical factorial of 'n-r'
    # Calculating the mathematical factorial of 'r'
    # Returning the binomial coefficient by dividing the factorial of 'n' by the product of factorials of 'n-r' and 'r'

# Iterating through each test case from 1 to K+1
for i in range(1,K+1):
  # Checking if the number of students required for the current test case is less than the number of extra students
  if N - K + 1 < i:
    # Initializing the answer to 0
    ans = 0
  else:
    # Calculating the binomial coefficient for the current test case using the 'fact' function
    ans = fact(R+1, i)*fact(K-1,i-1)
  # Printing the answer for the current test case
  print(int(ans)%mod)
