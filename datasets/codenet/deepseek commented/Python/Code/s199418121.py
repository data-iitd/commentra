
A, B = input().split()
# Taking input from the user and splitting it into two variables A and B
A = int(A)
# Converting variable A to an integer
B = int(B.replace(".", ""))
# Converting variable B to an integer by removing the decimal point
print(A * B // 100)
# Printing the result of the multiplication and integer division operation

