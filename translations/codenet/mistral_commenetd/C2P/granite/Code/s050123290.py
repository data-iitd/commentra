
N = 1000  # Define a constant N with the value 1000

while True:  # Start an infinite loop
    su = ""  # Initialize an empty string variable'su'
    susum = 0  # Initialize an integer variable'susum' to zero
    j = 0  # Initialize an integer variable 'j' to zero

    while True:  # Start an infinite loop
        char = input()  # Read a character from the standard input
        if char == "\n":  # If the character read is a newline character, break out of the loop
            break
        su += char  # Append the character to the string variable'su'
        susum += ord(char) - ord('0')  # Add the ASCII value of the character (after subtracting '0') to the variable'susum'

    if su[0] == '0':  # If the first character of the string variable'su' is '0', break out of the loop
        break
    print(susum)  # Print the sum of the digits read from the standard input
    susum = 0  # Reset the variable'susum' to zero for the next iteration
