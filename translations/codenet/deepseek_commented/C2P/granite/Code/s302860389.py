
# Read a string of four characters from the input
input_numbers = input()

# Initialize the second element of temp to the null character
temp = ['\0']

# Extract each digit from inputNumbers and convert it to an integer
a = int(input_numbers[0])
b = int(input_numbers[1])
c = int(input_numbers[2])
d = int(input_numbers[3])

# Nested loop structure to explore all combinations of addition and subtraction
for i in range(2):
    for j in range(2):
        for k in range(2):
            # Choose the operation based on the value of i
            if i == 0:
                sum = a + b
                symbol = '+'
            else:
                sum = a - b
                symbol = '-'

            # Choose the operation based on the value of j
            if j == 0:
                sum = sum + c
                symbol = '+'
            else:
                sum = sum - c
                symbol = '-'

            # Choose the operation based on the value of k
            if k == 0:
                sum = sum + d
                symbol = '+'
            else:
                sum = sum - d
                symbol = '-'

            # Check if the sum equals 7
            if sum == 7:
                # Print the expression if the sum is 7
                print(f"{a}{symbol}{b}{symbol}{c}{symbol}{d}=7")

                # Exit the program with a return value of 0
                exit(0)

# Return 0 if no combination results in a sum of 7
exit(0)

