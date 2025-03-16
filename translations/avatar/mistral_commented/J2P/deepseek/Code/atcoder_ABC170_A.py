def main():
    # Reading input from the console
    input_array = input().split()

    # Initializing result variable to 0
    result = 0

    # Iterating through each string in the input array
    for str in input_array:
        # Incrementing result variable for each non-zero string encountered
        result += 1

        # Breaking the loop if a zero string is encountered
        if str == '0':
            break

    # Printing the result to the console
    print(result)

# Calling the main method
if __name__ == "__main__":
    main()
