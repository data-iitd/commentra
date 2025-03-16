def main():
    INF = 10**15  # Initialize a constant value for large numbers

    # Read the number as a string from the user
    number = input()

    # Initialize an array of size number.length()+1 to store digits of the number
    digits = [0] * (len(number) + 1)

    # Loop through each digit of the number starting from the last digit
    for i in range(len(number)):
        digits[i] = int(number[len(number) - 1 - i])

    bills = 0  # Initialize a variable to store the total bill amount

    # Loop through each digit of the number including the last digit
    for i in range(len(number) + 1):
        if digits[i] == 10:  # If the current digit is 0
            digits[i + 1] += 1  # Increment the next digit
            digits[i] = 0  # Set the current digit to 0

        if digits[i] < 5:  # If the current digit is less than 5
            bills += digits[i]  # Add the digit value to the total bill amount
        elif digits[i] == 5:  # If the current digit is 5
            if i + 1 < len(number) + 1 and digits[i + 1] >= 5:  # If the next digit is also 5 or greater
                digits[i + 1] += 1  # Increment the next digit
            bills += 5  # Add 5 to the total bill amount
        else:  # If the current digit is greater than 5
            digits[i + 1] += 1  # Increment the next digit
            bills += 10 - digits[i]  # Add the difference between 10 and the current digit to the total bill amount

    print(bills)  # Print the total bill amount


main()
