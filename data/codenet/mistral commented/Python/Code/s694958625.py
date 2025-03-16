# Ask the user to input an integer value for x
x = int(input("Enter an integer value for x: "))

# Ask the user to input an integer value for a
a = int(input("Enter an integer value for a: "))

# Ask the user to input an integer value for b
b = int(input("Enter an integer value for b: "))

# Calculate the difference between x and a
diff = x - a

# Calculate the remainder of the division of diff by b
remainder = diff % b

# Print the remainder
print("The remainder of the division of", x, "-", a, "by", b, "is:", remainder)