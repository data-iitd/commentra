def main():
    # Read a string of numbers from user input
    input_numbers = input()

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
                    sum = a + b  # Perform addition
                    symbol1 = '+'  # Store the symbol used
                else:
                    sum = a - b  # Perform subtraction
                    symbol1 = '-'  # Store the symbol used

                # Determine the second operation (addition or subtraction with c)
                if j == 0:
                    sum = sum + c  # Perform addition
                    symbol2 = '+'  # Store the symbol used
                else:
                    sum = sum - c  # Perform subtraction
                    symbol2 = '-'  # Store the symbol used

                # Determine the third operation (addition or subtraction with d)
                if k == 0:
                    sum = sum + d  # Perform addition
                    symbol3 = '+'  # Store the symbol used
                else:
                    sum = sum - d  # Perform subtraction
                    symbol3 = '-'  # Store the symbol used

                # Check if the calculated sum equals 7
                if sum == 7:
                    # Print the expression that results in 7
                    print(f"{a}{symbol1}{b}{symbol2}{c}{symbol3}{d}=7")
                    
                    return  # Exit the program after finding the first valid expression

if __name__ == "__main__":
    main()
