
import re

def luhn_check(digits):
    numbers = list(digits) # Create a copy of the input array to modify it in place
    sum = 0 # Initialize sum variable to store the sum of digits

    for i in range(len(numbers) - 1, -1, -1): # Iterate through the array from the last digit to the first one
        if (len(numbers) - i) % 2 == 0: # If the current index is even
            temp = numbers[i] * 2 # Multiply the current digit by 2
            if temp > 9: # If the result is greater than 9
                temp -= 9 # Subtract 9 to get the first digit of the result
            numbers[i] = temp # Update the current digit with the first digit of the result
        sum += numbers[i] # Add the current digit (or its doubled value) to the sum

    return sum % 10 == 0 # Return true if the sum is a multiple of 10, indicating a valid number according to the Main algorithm

def main():
    sc = input("Enter a credit card number: ") # Read the credit card number as a string from the console

    try:
        card_number = re.sub(r'\s+', '', sc) # Remove any spaces from the input string
        card_numbers = [int(x) for x in card_number] # Convert the input string to an array of integers

        if len(card_numbers) != 16 or not all(x.isdigit() for x in card_numbers): # Check if the input string has the correct length and is composed only of digits
            raise ValueError("{" + sc + "} - is not a valid card number") # Throw an exception if the input is invalid

        if not luhn_check(card_numbers): # Check if the input digits form a valid number according to the Main algorithm
            raise ValueError("Credit card number {" + sc + "} failed the Main check") # Throw an exception if the input is invalid

        print("Credit card is valid: " + sc) # Print the valid credit card object
    except ValueError as e:
        print("Error: " + str(e)) # Print the error message if the input is invalid

if __name__ == "__main__":
    main()

