# Main function starts here
def main():
    # Start an infinite loop
    while True:
        # Read a string from the user input
        str_input = input()

        # Check if the user wants to exit by entering "0"
        if str_input == "0":
            # Exit the loop if user enters "0"
            break

        # Initialize sum variable to zero
        total_sum = 0

        # Iterate through each character in the string
        for char in str_input:
            # Convert the character to an integer and add it to the sum
            num = int(char)
            total_sum += num

        # Print the sum of the digits in the string
        print(total_sum)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
