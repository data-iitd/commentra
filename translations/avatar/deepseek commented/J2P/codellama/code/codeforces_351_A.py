
import sys

# Step 1: Reading Input
n = int ( sys.stdin.readline ( ) )
st = sys.stdin.readline ( ).split ( )

# Step 2: Processing Input
arr = [ ]
non_int = 0
sum_before = 0
sum = 0

for i in range ( 2 * n ) :
    num = float ( st [ i ] )
    sum_before += num
    if num != int ( num ) :
        non_int += 1
    sum += int ( num )
    arr.append ( num )

# Step 3: Calculating Results
max_sum = min ( n , non_int ) + sum
min_sum = max ( 0 , non_int - n ) + sum
ans = 0

if min_sum > sum_before :
    ans = min_sum - sum_before
elif max_sum < sum_before :
    ans = sum_before - max_sum
else :
    x = sum_before - int ( sum_before )
    ans = min ( 1 - x , x )

# Step 4: Output
print ( "%.3f" % ans )

