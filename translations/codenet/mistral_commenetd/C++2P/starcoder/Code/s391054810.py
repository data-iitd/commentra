
# Declare four integer variables: h, w, hh, and ww.
h, w, hh, ww = 0, 0, 0, 0

# Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
h, w, hh, ww = map(int, input().split())

# Calculate the difference between h and hh and the difference between w and ww.
difference_h = h - hh
difference_w = w - ww

# Output the product of the differences to the standard output.
print("The area of the rectangle is: " + str(difference_h * difference_w))

# 