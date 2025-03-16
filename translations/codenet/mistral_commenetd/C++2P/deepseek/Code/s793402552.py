# Read two integers `a` and `b` from the standard input
a, b = map(int, input().split())

# Convert the integer `b` to a string `bstr` using the `str()` function
bstr = str(b)

# Calculate the number `num` as the product of `a` and `10` raised to the power of the length of the string `bstr`, plus the integer `b`
num = a * (10 ** len(bstr)) + b

# Initialize a loop counter `i`
i = 1

# Enter a `while` loop that runs until `i * i` is greater than `num`
while i * i <= num:
    # Inside the loop, check if the square of `i` is equal to the number `num`
    if i * i == num:
        # If it is, break out of the loop
        break
    # Increment the loop counter `i`
    i += 1

# If the loop completes without finding a square root of `num`, print "No" to the standard output
if i * i > num:
    print("No")
# If we find a square root of `num` inside the loop, print "Yes" to the standard output
else:
    print("Yes")
