
import sys

# Step 1: Reading Input
n = int ( sys.stdin.readline ( ).strip ( ) ) # Read the integer n
arr = list ( map ( float, sys.stdin.readline ( ).strip ( ).split ( " " ) ) ) # Read the second line of input

# Step 2: Processing Input
non_int = 0 # Counter for non-integer values
sum_before = 0 # Variable to store the sum of all numbers
sum = 0 # Variable to store the sum of integer parts

for i in range ( 2 * n ) :
    num = arr [ i ] # Get the number
    sum_before += num # Add to the sum of all numbers
    if ( num!= int ( num ) ) : non_int += 1 # Increment counter if the number is not an integer
    sum += int ( num ) # Add the integer part of the number to the sum of integer parts

# Step 3: Calculating Results
max_sum = min ( n, non_int ) + sum # Calculate the maximum possible sum
min_sum = max ( 0, non_int - n ) + sum # Calculate the minimum possible sum
ans = 0 # Variable to store the result

if ( min_sum > sum_before ) :
    ans = min_sum - sum_before # If the minimum sum is greater than the actual sum
elif ( max_sum < sum_before ) :
    ans = sum_before - max_sum # If the maximum sum is less than the actual sum
else :
    x = sum_before - int ( sum_before ) # Calculate the fractional part of the sum
    ans = min ( 1 - x, x ) # Find the smallest difference to 0 or 1

# Step 4: Output
print ( "%.3f" % ans ) # Print the result with a precision of three decimal places

