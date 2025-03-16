# Import the map function from the built-in module
# This function is used to convert a list of items into a list of corresponding int values
# map(function, iterable, ...)
# In this case, the function is the built-in int() function
# The iterable is the list obtained by splitting the input string using the split() method
map = builtins.map

# Define three variables and assign them the values obtained from the input
# The input is split into three parts using the split() method and then converted to integers using the map() function
N, A, B = map(int, input().split())

# Initialize an empty variable named ans which will be used to store the answer
ans = 0

# Calculate the quotient of N by the sum of A and B and assign the integer part of the result to ans
ans = A * (N // (A + B))

# Calculate the minimum of A and the remainder of N when divided by the sum of A and B
# Assign this value to ans if the value of A is smaller than the remainder
if A > N % (A + B):
    ans += N % (A + B)

# Print the value of ans to the console
print(ans)
