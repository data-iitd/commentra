# Declare variables to hold input numbers and intermediate values
input_numbers = input("Enter four digits: ")  # Read a string of numbers from user input

# Convert each character to an integer and store in respective variables
a = int(input_numbers[0])
b = int(input_numbers[1])
c = int(input_numbers[2])
d = int(input_numbers[3])

# Iterate through all combinations of addition and subtraction for the four numbers
for i in range(2):  # Loop for the first operation (a + b or a - b)
    for j in range(2):  # Loop for the second operation (result + c or result - c)
        for k in range(2):  # Loop for the third operation (result + d or result - d)
            # Determine the first operation (addition or subtraction with a and b)
            if i == 0:
                sum_result = a + b  # Perform addition
                symbols = ['+', '']  # Store the symbol used
            else:
                sum_result = a - b  # Perform subtraction
                symbols = ['-', '']  # Store the symbol used

            # Determine the second operation (addition or subtraction with c)
            if j == 0:
                sum_result += c  # Perform addition
                symbols[1] = '+'  # Store the symbol used
            else:
                sum_result -= c  # Perform subtraction
                symbols[1] = '-'  # Store the symbol used

            # Determine the third operation (addition or subtraction with d)
            if k == 0:
                sum_result += d  # Perform addition
                symbols.append('+')  # Store the symbol used
            else:
                sum_result -= d  # Perform subtraction
                symbols.append('-')  # Store the symbol used

            # Check if the calculated sum equals 7
            if sum_result == 7:
                # Print the expression that results in 7
                print(f"{a}{symbols[0]}{b}{symbols[1]}{c}{symbols[2]}{d}=7")
                exit()  # Exit the program after finding the first valid expression

# End of the program
# If no expression was found, the program will simply end without output
# <END-OF-CODE>
