def main():
    # Define a constant for infinity
    INF = int(1e15)
    
    # Read the input number as a string
    number = input()
    
    # Create a list to store the digits of the number
    digits = [0] * (len(number) + 1)
    
    # Convert the number into a list of digits
    for i in range(len(number)):
        digits[i] = int(number[len(number) - 1 - i])
    
    # Initialize the total bill to 0
    bills = 0
    
    # Loop through each digit to calculate the total bill
    for i in range(len(number) + 1):
        # Handle the case where the digit is 10
        if digits[i] == 10:
            digits[i + 1] += 1
            digits[i] = 0
        
        # Add the digit to the bill if it is less than 5
        if digits[i] < 5:
            bills += digits[i]
        # Handle the case where the digit is 5
        elif digits[i] == 5:
            if digits[i + 1] >= 5:
                digits[i + 1] += 1
            bills += 5
        # Handle the case where the digit is greater than 5
        else:
            digits[i + 1] += 1
            bills += 10 - digits[i]
    
    # Print the total bill
    print(bills)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
