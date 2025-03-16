# Read two integers `a` and `b` from the standard input
a, b = map(int, input().split())

# Convert the integer `b` to a string `bstr`
bstr = str(b)

# Calculate the number `num` as the product of `a` and 10 raised to the power of the length of the string `bstr`, plus the integer `b`
num = a * (10 ** len(bstr)) + b

# Initialize a loop counter `i`
i = 1

# Enter a loop that runs from `1` to `100100`
while i <= 100100:
    # Check if the square of `i` is equal to the number `num`
    if i * i == num:
        # If it is, break out of the loop
        break
    i += 1

# If the loop completes without finding a square root of `num`, print "No"
if i > 100100:
    print("No")
# If we find a square root of `num` inside the loop, print "Yes"
else:
    print("Yes")

# <END-OF-CODE>
