# Declare a function to handle the main logic
def main():
    # Infinite loop to continuously accept input until "0" is entered
    while True:
        # Read input from the user
        str_input = input()

        # Check if the input is "0", if so, exit the loop
        if str_input == "0":
            break

        # Initialize sum to 0 for the new input string
        total_sum = 0

        # Loop through each character in the input string
        for char in str_input:
            # Convert the character to an integer and add to the sum
            total_sum += int(char)

        # Output the sum of the digits for the current input string
        print(total_sum)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
