# Declare a variable named 'age' and assign it the value of an integer input from the user
age = int(input())

# Check if the value of 'age' is equal to 1
if age == 1:
    # If the condition is met, print 'Hello World'
    print('Hello World')
else:
    # If the condition is not met, declare two variables 'a' and 'b' and assign them the values of two integer inputs from the user
    a, b = [int(input()) for i in range(2)]
    # Print the sum of 'a' and 'b'
    print(a + b)
