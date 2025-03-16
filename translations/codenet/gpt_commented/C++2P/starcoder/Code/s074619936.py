# <START-OF-CODE>

# Infinite loop to continuously accept input until "0" is entered
while(1):
    # Read input from the user
    str = input()

    # Check if the input is "0", if so, exit the loop
    if(str == "0"): break

    # Initialize sum to 0 for the new input string
    sum = 0

    # Loop through each character in the input string
    for i in range(len(str)):
        # Convert the character to a string
        tmp = str[i]

        # Convert the string character to an integer
        num = int(tmp)

        # Add the integer value to the sum
        sum += num

    # Output the sum of the digits for the current input string
    print(sum)

# 