
a, b = input().split(" ")
# Taking input from the user and splitting it into two parts based on a space
a = int(a)
b = int(b)
# Converting the split input into integers
if a <= b:
    # Checking if the first integer is less than or equal to the second integer
    print(a)
    # If true, print the first integer
else:
    print(a-1)
    # If false, print the first integer minus one

