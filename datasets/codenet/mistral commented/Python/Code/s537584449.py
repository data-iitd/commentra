# Take an integer input from the user
a = int(input())

# Define a function named 'func' that takes an integer argument 'a'
def func(a):

    # Initialize an empty list 'digits' to store the digits of the number
    digits = []

    # Assign the value of 'a' to the variable 'temp'
    temp = a

    # Use a 'while' loop to extract digits one by one from the number
    while temp != 0:

        # Append the last digit of 'temp' to the 'digits' list
        digits.append(temp%10)

        # Divide 'temp' by 10 to get the next digit
        temp = int(temp/10)

    # Calculate the sum of all digits and store it in the variable 'result'
    result = sum(digits)

    # Check if the sum of digits is equal to 1
    if result == 1:

        # If yes, print the string '10'
        print('10')

    # If not, print the value of 'result'
    else:
        print(result)

# Call the function 'func' with the input 'a' as an argument
func(a)