class Main:
    @staticmethod
    def divide(dividend, divisor):
        new_dividend = dividend  # Assign the dividend to a variable for easier manipulation
        new_divisor = divisor  # Assign the divisor to a variable for easier manipulation

        if divisor == 0:  # Check if the divisor is zero
            raise ZeroDivisionError("Division by zero")  # Raise an exception if the divisor is zero

        if dividend < 0:  # Check if the dividend is negative
            new_dividend = -new_dividend  # Make the dividend positive

        if divisor < 0:  # Check if the divisor is negative
            new_divisor = -new_divisor  # Make the divisor positive

        if dividend == 0 or new_dividend < new_divisor:  # Check if the dividend is zero or the quotient is less than zero
            return 0  # Return zero if the dividend is zero or the quotient is less than zero

        answer = []  # Create a list to store the quotient digits
        dividend_string = str(new_dividend)  # Convert the dividend to a string
        last_index = 0  # Initialize the last index of the string to 0
        remainder = ""  # Initialize the remainder as an empty string

        for i in range(len(dividend_string)):  # Iterate through each digit of the dividend string
            part = remainder + dividend_string[last_index:i + 1]  # Concatenate the remainder and the current digit
            part1 = int(part)  # Parse the part of the dividend as an integer

            if part1 >= new_divisor:  # Check if the current part is greater than or equal to the divisor
                quotient = 0  # Initialize the quotient to zero
                while part1 >= new_divisor:  # Subtract the divisor from the current part until it's less than the divisor
                    part1 -= new_divisor
                    quotient += 1  # Increment the quotient by 1 for each subtraction
                answer.append(quotient)  # Append the quotient to the list
            else:  # If the current part is less than the divisor, append a zero to the list
                answer.append(0)

            remainder = str(part1) if part1 != 0 else ""  # Update the remainder for the next iteration
            last_index += 1  # Increment the last index of the string

        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):  # Check if the dividend and divisor have opposite signs
            try:
                return int(''.join(map(str, answer))) * -1  # Multiply the quotient by -1 and return the result
            except ValueError:
                return -2147483648  # Return the minimum integer value if there's an error parsing the quotient

        try:
            return int(''.join(map(str, answer)))  # Parse the quotient as an integer and return the result
        except ValueError:
            return 2147483647  # Return the maximum integer value if there's an error parsing the quotient

if __name__ == "__main__":
    dividend = int(input("Enter dividend: "))  # Read the dividend from the console as an integer
    divisor = int(input("Enter divisor: "))  # Read the divisor from the console as an integer

    try:
        result = Main.divide(dividend, divisor)  # Call the divide method to calculate the quotient
        print("Result:", result)  # Print the quotient to the console
    except ZeroDivisionError as e:
        print("Error:", e)  # Print the error message to the console if there's an error
