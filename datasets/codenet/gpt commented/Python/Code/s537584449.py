# Take an integer input from the user
a = int(input())

# Define a function that processes the input integer
def func(a):
    # Initialize an empty list to store the digits of the number
    digits = []
    # Create a temporary variable to hold the value of 'a' for manipulation
    temp = a
    
    # Extract digits from the number until there are no more digits left
    while temp != 0:
        # Append the last digit of 'temp' to the digits list
        digits.append(temp % 10)
        # Remove the last digit from 'temp' by performing integer division
        temp = int(temp / 10)
    
    # Calculate the sum of the extracted digits
    result = sum(digits)
    
    # Check if the sum of the digits is equal to 1
    if result == 1:
        # If the sum is 1, print '10'
        print('10')
    else:
        # Otherwise, print the sum of the digits
        print(result)

# Call the function with the user input
func(a)
