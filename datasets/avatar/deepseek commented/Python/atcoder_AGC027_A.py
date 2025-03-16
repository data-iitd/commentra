
na = lambda : list ( map ( int , input ( ).split ( ) ) )
# Define a lambda function to read input and convert it to a list of integers

n , x = na ( )
# Read the values of n and x from input

a = sorted ( na ( ) )
# Read the list `a` from input, then sort it in ascending order

ans = 0
# Initialize the variable `ans` to store the result

if a [ 0 ] > x :
    print ( 0 )
    exit ( )
# Check if the smallest element in the sorted list `a` is greater than `x`. If so, print 0 and exit.

for i in a :
    if i > x :
        x = 0
        break
    x -= i
    ans += 1
# Iterate through each element in the sorted list `a`, subtracting each element from `x` and incrementing `ans` until `x` becomes 0 or an element greater than `x` is encountered.

if x != 0 :
    ans -= 1
# If `x` is not 0 after the loop, decrement `ans` by 1.

print ( ans )
# Print the value of `ans`.