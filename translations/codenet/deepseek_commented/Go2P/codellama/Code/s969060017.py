
# Declare two integer variables `a` and `b` to store input values
a, b = input(), input()

# Check if `b` is divisible by `a` without a remainder
if b % a == 0:
    # If `b` is divisible by `a`, print the sum of `a` and `b`
    print(int(a) + int(b))
else:
    # If `b` is not divisible by `a`, print the difference between `b` and `a`
    print(int(b) - int(a))

