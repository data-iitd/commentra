# Python code to achieve the same functionality as the provided Go code

# Function main initializes the program and starts the execution flow
def main():
    # Declare a variable named S of type string
    S = input()

    # Switch statement to check the value of the string S and print the corresponding weather condition
    if S == "Sunny":
        print("Cloudy")
    elif S == "Cloudy":
        print("Rainy")
    elif S == "Rainy":
        print("Sunny")

# Call the main function to execute the program
main()

# End of the code
