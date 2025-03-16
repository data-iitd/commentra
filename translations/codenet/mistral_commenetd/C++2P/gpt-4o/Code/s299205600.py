# Declare and initialize variable 'a' to store first user input
a = int(input())  # Read the first integer value from the user
# Declare and initialize variable 'b' to store second user input
b = int(input())  # Read the second integer value from the user

# Declare variable 'result' to store the result of the computation
if a > b:  # Check if 'a' is greater than 'b'
    result = 2 * a - 1  # If true, assign the value '2 * a - 1' to 'result'
elif a == b:  # Check if 'a' is equal to 'b'
    result = 2 * a  # If true, assign the value '2 * a' to 'result'
else:  # If 'a' is less than 'b'
    result = 2 * b - 1  # Assign the value '2 * b - 1' to 'result'

print(result)  # Print the value of 'result' to the console

# Terminate the program
# <END-OF-CODE>
