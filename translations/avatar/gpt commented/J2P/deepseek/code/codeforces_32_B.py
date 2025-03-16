import sys

def main():
    # Reading a string input from the console
    n = input()
    
    # Initializing a boolean variable to track the state of the previous character
    s = False
    
    # Iterating through each character in the string
    for char in n:
        # Checking if the current character is a dot '.'
        if char == '.':
            # If the previous character was also a dot, print 1 and reset the state
            if s:
                print(1, end='')
                s = False  # Resetting the state
            else:
                # If the previous character was not a dot, print 0
                print(0, end='')
        else:
            # If the current character is not a dot
            if s:
                # If the previous character was also not a dot, print 2 and reset the state
                print(2, end='')
                s = False  # Resetting the state
            else:
                # If the previous character was a dot, set the state to True
                s = True

if __name__ == "__main__":
    main()
