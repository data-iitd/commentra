
# Declare four integer variables: h, w, hh, and ww.
h = 0
w = 0
hh = 0
ww = 0

# Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
h = int(input())
w = int(input())
hh = int(input())
ww = int(input())

# Calculate the difference between h and hh and the difference between w and ww.
difference_h = h - hh
difference_w = w - ww

# Output the product of the differences to the standard output.
print("The area of the rectangle is: " + str(difference_h * difference_w))

# Return 0 to indicate successful termination of the program.
return 0

