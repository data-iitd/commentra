# Main function where the program execution begins
def main():
    # Array to store the input numbers as characters
    input_numbers = input("Enter four digits: ")
    
    # Extract each digit from input_numbers and convert it to an integer
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
                    sum_result = a + b
                    symbol_0 = '+'
                else:
                    sum_result = a - b
                    symbol_0 = '-'

                # Choose the operation based on the value of j
                if j == 0:
                    sum_result += c
                    symbol_1 = '+'
                else:
                    sum_result -= c
                    symbol_1 = '-'

                # Choose the operation based on the value of k
                if k == 0:
                    sum_result += d
                    symbol_2 = '+'
                else:
                    sum_result -= d
                    symbol_2 = '-'

                # Check if the sum equals 7
                if sum_result == 7:
                    # Print the expression if the sum is 7
                    print(f"{a}{symbol_0}{b}{symbol_1}{c}{symbol_2}{d}=7")
                    
                    # Exit the program
                    return

    # Return if no combination results in a sum of 7
    return

# Call the main function
main()

# <END-OF-CODE>
