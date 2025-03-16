def main():
    # Read input from the user and convert it to a character array
    str = input()
    
    # Initialize variable to store the index of the decimal point
    dot_index = 0
    
    # Find the index of the decimal point in the input
    for i in range(len(str)):
        if str[i] == '.':
            dot_index = i
            break
    
    # Check if the digit before the decimal point is '9'
    if str[dot_index - 1] == '9':
        # If it is, print a specific message
        print("GOTO Vasilisa.")
    # Check if the digit after the decimal point is greater than 4
    elif int(str[dot_index + 1]) > 4:
        # If it is, create a new string from the integer part and add 1
        _str = ""
        for i in range(dot_index):
            _str += str[i]
        # Print the incremented value
        print(str(int(_str) + 1))
    # If the digit after the decimal point is 4 or less
    else:
        # Print the integer part as it is
        for i in range(dot_index):
            print(str[i], end='')
        print()

if __name__ == "__main__":
    main()
