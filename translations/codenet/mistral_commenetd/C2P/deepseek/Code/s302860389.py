def find_combination():
    # Initialize variables
    input_numbers = [0] * 4
    symbols = ['+', '+', '+']

    # Read input numbers from user
    input_numbers_str = input("Enter four integers separated by spaces: ")
    input_numbers = list(map(int, input_numbers_str.split()))

    # Perform arithmetic operations and check for the sum equal to 7
    for i in range(2):  # outer loop
        for j in range(2):  # middle loop
            for k in range(2):  # inner loop
                # Assign symbols based on the position of current number
                if i == 0:
                    sum = input_numbers[0] + input_numbers[1]
                    symbols[0] = '+'
                else:
                    sum = input_numbers[0] - input_numbers[1]
                    symbols[0] = '-'

                if j == 0:
                    sum = sum + input_numbers[2]
                    symbols[1] = '+'
                else:
                    sum = sum - input_numbers[2]
                    symbols[1] = '-'

                if k == 0:
                    sum = sum + input_numbers[3]
                    symbols[2] = '+'
                else:
                    sum = sum - input_numbers[3]
                    symbols[2] = '-'

                # Check if the sum is equal to 7
                if sum == 7:
                    print(f"{input_numbers[0]}{symbols[0]}{input_numbers[1]}{symbols[1]}{input_numbers[2]}{symbols[2]}{input_numbers[3]} = 7")
                    return 0

    # If no combination of four numbers results in a sum of 7, return 0
    return 0

find_combination()
