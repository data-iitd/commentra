import sys

def main():
    # Initialize an empty list 'm' to store the multipliers
    m = [10, 50, 100, 500]

    first = True  # Initialize a boolean variable 'first' to check if it's the first iteration of the loop

    # Main loop to read the input money and calculate the change
    for line in sys.stdin:
        money = int(line.strip())
        if money == 0:
            break  # Exit the loop if the input is 0

        # If it's not the first iteration, print a newline character to separate the outputs
        if not first:
            print()

        # Set 'first' to false
        first = False

        # Initialize variables 'sum' and 'num'
        sum_value = 0
        num = [0] * 4

        # Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
        for i in range(4):
            num[i] = int(input().strip())  # Read the number
            sum_value += num[i] * m[i]  # Calculate the product and add it to the sum

        # Calculate the change
        change = sum_value - money

        # Adjust the numbers to get the exact change
        for i in range(3, -1, -1):
            if change // m[i]:
                num[i] -= change // m[i]
                change %= m[i]

        # Print the numbers that still have a positive value
        for i in range(4):
            if num[i] > 0:
                print(m[i], num[i])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
