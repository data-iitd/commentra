def main():
    # Reading an integer value from the user input
    x = int(input())

    # Determining a boolean value based on the condition x equals to 1
    bool_val = x == 1

    # Calculating the result based on the boolean value
    result = 1 if not bool_val else 0

    # Printing the result to the standard output
    print(result)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()
