n = int(input())  # Read the number of elements 'n' from the standard input

a = [0] * 100  # Declare a list 'a' of size 100
b = [0] * 100  # Declare a list 'b' of size 100
sum = 0  # Initialize a variable 'sum' to zero

for i in range(n):  # Iterate through the list 'a' and read its elements from the standard input
    a[i] = int(input())

for i in range(n):  # Iterate through the list 'b' and read its elements from the standard input
    b[i] = int(input())
    
    if a[i] - b[i] > 0:  # Check if the difference between 'a[i]' and 'b[i]' is positive
        sum += a[i] - b[i]  # If it is, add the difference to the variable 'sum'

print(sum)  # Output the value of the variable 'sum' to the standard output
# <END-OF-CODE>
