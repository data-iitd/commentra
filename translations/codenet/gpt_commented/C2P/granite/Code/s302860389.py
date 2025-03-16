
# Python code to solve the problem

# Read a string of numbers from user input
input_numbers = input("Enter a string of numbers: ")

# Convert the input string to a list of integers
numbers = [int(char) for char in input_numbers]

# Iterate through all combinations of addition and subtraction for the four numbers
for i in range(2): # Loop for the first operation (a + b or a - b)
    for j in range(2): # Loop for the second operation (result + c or result - c)
        for k in range(2): # Loop for the third operation (result + d or result - d)
            # Determine the first operation (addition or subtraction with a and b)
            if i == 0:
                result = numbers[0] + numbers[1] # Perform addition
                symbol = '+' # Store the symbol used
            else:
                result = numbers[0] - numbers[1] # Perform subtraction
                symbol = '-' # Store the symbol used

            # Determine the second operation (addition or subtraction with c)
            if j == 0:
                result = result + numbers[2] # Perform addition
                symbol = '+' # Store the symbol used
            else:
                result = result - numbers[2] # Perform subtraction
                symbol = '-' # Store the symbol used

            # Determine the third operation (addition or subtraction with d)
            if k == 0:
                result = result + numbers[3] # Perform addition
                symbol = '+' # Store the symbol used
            else:
                result = result - numbers[3] # Perform subtraction
                symbol = '-' # Store the symbol used

            # Check if the calculated result equals 7
            if result == 7:
                # Print the expression that results in 7
                print(f"{numbers[0]}{symbol}{numbers[1]}{symbol}{numbers[2]}{symbol}{numbers[3]}=7")
                
                break # Exit the nested loops after finding the first valid expression

# End of Python code

