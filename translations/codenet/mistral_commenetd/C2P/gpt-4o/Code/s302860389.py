# Declare variables
input_numbers = ""
temp = ""
a, b, c, d = 0, 0, 0, 0
sum_result = 0
symbols = ['+', '+', '+']

# Read input numbers from user
input_numbers = input("Enter four integers separated by spaces: ")

# Extract each number from input string and convert to integer
numbers = input_numbers.split()
a = int(numbers[0])
b = int(numbers[1])
c = int(numbers[2])
d = int(numbers[3])

# Perform arithmetic operations and check for the sum equal to 7
for i in range(2):  # outer loop
    for j in range(2):  # middle loop
        for k in range(2):  # inner loop
            # Assign symbols based on the position of current number
            if i == 0:
                sum_result = a + b
                symbols[0] = '+'
            else:
                sum_result = a - b
                symbols[0] = '-'

            if j == 0:
                sum_result += c
                symbols[1] = '+'
            else:
                sum_result -= c
                symbols[1] = '-'

            if k == 0:
                sum_result += d
                symbols[2] = '+'
            else:
                sum_result -= d
                symbols[2] = '-'

            # Check if the sum is equal to 7
            if sum_result == 7:
                print(f"{a}{symbols[0]}{b}{symbols[1]}{c}{symbols[2]}{d} = 7")

                # If sum is equal to 7, exit the loop and return
                exit()

# If no combination of four numbers results in a sum of 7, return
# (In Python, we simply end the program)
# <END-OF-CODE>
