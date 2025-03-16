
# Declare three integer variables: A, B, and flag
A, B, flag = 0, 0, 0

# Read two integers from the standard input and store them in variables A and B
A, B = map(int, input().split())

# Iterate from 1 to 3 using a for loop
for i in range(1, 4):
  # Check if the product of A, B, and the loop counter i is odd
  if((A*B*i)%2 == 1):
    # Set the flag variable to 1 if the condition is true
    flag = 1
    # Break out of the loop if the condition is true
    break

# Check the value of the flag variable
if(flag):
  # Print "Yes" to the standard output if the flag variable is 1
  print("Yes")
else:
  # Print "No" to the standard output if the flag variable is 0
  print("No")

# Return 0 to indicate successful execution of the program
return 0

