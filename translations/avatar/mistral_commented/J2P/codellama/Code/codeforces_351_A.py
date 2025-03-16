
import math
import sys

# Reading the number of test cases
n = int ( sys.stdin.readline ( ) )

# Reading the elements of the array
arr = list ( map ( float , sys.stdin.readline ( ).split ( ) ) )

# Calculating the sum of the array elements
sum = sum ( arr )

# Calculating the sum of the floor values of the array elements
sum_floor = sum ( map ( math.floor , arr ) )

# Calculating the sum of the ceil values of the array elements
sum_ceil = sum ( map ( math.ceil , arr ) )

# Calculating the maximum and minimum sums
max_sum = max ( sum_floor , sum_ceil )
min_sum = min ( sum_floor , sum_ceil )

# Calculating the answer based on the given conditions
ans = 0
if min_sum > sum :
    ans = min_sum - sum
elif max_sum < sum :
    ans = sum - max_sum
else :
    x = sum - math.floor ( sum )
    ans = min ( 1 - x , x )

# Printing the answer
print ( round ( ans , 3 ) )

