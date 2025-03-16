
na = lambda : list ( map ( int , input ( ).split ( ) ) )
# Define an anonymous function `na` that takes no arguments and returns a list of integers obtained by mapping the `int` function to each element of the input list, which is split by spaces.

n, x = na( )
# Unpack the list returned by `na` into two variables `n` and `x`.

a = sorted(na( ))
# Sort the list returned by `na` and assign it to the variable `a`.

ans = 0
# Initialize the variable `ans` to 0.

if a[0] > x:
# Check if the first element of `a` is greater than `x`.
    print(0)
    exit()
# If it is, print 0 and exit the program.

for i in a:
# Iterate through each element `i` in `a`.
    if i > x:
# If the current element `i` is greater than `x`, set `x` to 0 and break the loop.
        x = 0
        break
# If the current element `i` is less than or equal to `x`, subtract it from `x` and increment `ans` by 1.

    x -= i
# Subtract the current element `i` from `x`.

    ans += 1
# Increment `ans` by 1.

if x != 0:
# If `x` is not equal to 0 after the loop, decrement `ans` by 1.
    ans -= 1

print(ans)
# Print the final value of `ans`.