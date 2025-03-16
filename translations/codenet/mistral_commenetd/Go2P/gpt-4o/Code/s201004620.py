# The entry point of the program
def main():
    # Read a string input from the standard input
    S = input()

    # Check the value of the string S and print the corresponding weather condition
    if S == "Sunny":  # If the input string is "Sunny"
        print("Cloudy")  # Print "Cloudy" as the output
    elif S == "Cloudy":  # If the input string is "Cloudy"
        print("Rainy")  # Print "Rainy" as the output
    elif S == "Rainy":  # If the input string is "Rainy"
        print("Sunny")  # Print "Sunny" as the output

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
