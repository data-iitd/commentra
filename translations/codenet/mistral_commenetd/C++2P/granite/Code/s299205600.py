

a = int(input()) # Read the first integer value from the user
b = int(input()) # Read the second integer value from the user

if a > b: # Check if 'a' is greater than 'b'
    result = 2 * a - 1 # If true, assign the value '2 * a - 1' to'result'
elif a == b: # Check if 'a' is equal to 'b'
    result = 2 * a # If true, assign the value '2 * a' to'result'
else: # If 'a' is less than 'b'
    result = 2 * b - 1 # Assign the value '2 * b - 1' to'result'

print(result) # Print the value of'result' to the console

