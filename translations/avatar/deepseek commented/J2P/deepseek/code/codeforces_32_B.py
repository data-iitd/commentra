def main():
    n = list(input())  # Read the input string and convert it to a list of characters
    s = False  # Initialize a boolean variable to keep track of the state

    # Process each character in the list
    for i in range(len(n)):
        if n[i] == '.':  # Check if the current character is a dot
            if s:  # If the state is True
                print(1, end='')  # Print '1' and reset the state to False
                s = False
            else:  # If the state is False
                print(0, end='')  # Print '0' and set the state to False
                s = False
        else:  # If the current character is not a dot
            if s:  # If the state is True
                print(2, end='')  # Print '2' and reset the state to False
                s = False
            else:  # If the state is False
                s = True  # Set the state to True


if __name__ == "__main__":
    main()
