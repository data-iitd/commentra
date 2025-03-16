# Prompt the user to input their age and convert it to an integer
age = int(input())

# Check if the age is equal to 1
if age == 1:
    # If age is 1, print 'Hello World'
    print('Hello World')
else:
    # If age is not 1, prompt the user to input two integers
    a, b = [int(input()) for i in range(2)]
    # Calculate and print the sum of the two integers
    print(a + b)
