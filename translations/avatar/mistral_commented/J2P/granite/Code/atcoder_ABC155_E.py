

number = input ( )  # Read the number as a String from the user

digits = [ int ( digit ) for digit in number [ :: - 1 ] ]  # Convert the number to a list of digits in reverse order

bills = 0  # Initialize a variable to store the total bill amount

for i in range ( len ( digits ) + 1 ) :  # Loop through each digit of the number including the last digit
    if digits [ i ] == 10 :  # If the current digit is 0
        digits [ i + 1 ] += 1  # Increment the next digit
        digits [ i ] = 0  # Set the current digit to 0
    if digits [ i ] < 5 :  # If the current digit is less than 5
        bills += digits [ i ]  # Add the digit value to the total bill amount
    elif digits [ i ] == 5 :  # If the current digit is 5
        if digits [ i + 1 ] >= 5 :  # If the next digit is also 5 or greater
            digits [ i + 1 ] += 1  # Increment the next digit
        bills += 5  # Add 5 to the total bill amount
    else :  # If the current digit is greater than 5
        digits [ i + 1 ] += 1  # Increment the next digit
        bills += 10 - digits [ i ]  # Add the difference between 10 and the current digit to the total bill amount

print ( bills )  # Print the total bill amount

