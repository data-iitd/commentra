
import sys

# Reading the number of test cases
n = int ( input ( ) )

# Reading the elements of the array
arr = list ( map ( float, input ( ).split ( ) ) )

# Initializing variables
non_int = 0
sum_before = 0
sum = 0

# Iterating through the array elements and performing the required operations
for i in range ( 2 * n ) :
    num = arr [ i ]
    sum_before += num
    if ( num!= int ( num ) ) :
        non_int += 1
    sum += int ( num )

# Calculating the maximum and minimum sums
max_sum = min ( n, non_int ) + sum
min_sum = max ( 0, non_int - n ) + sum

# Calculating the answer based on the given conditions
ans = 0
if ( min_sum > sum_before ) :
    ans = min_sum - sum_before
elif ( max_sum < sum_before ) :
    ans = sum_before - max_sum
else :
    x = sum_before - int ( sum_before )
    ans = min ( 1 - x, x )

# Printing the answer
print ( round ( ans, 3 ) )

