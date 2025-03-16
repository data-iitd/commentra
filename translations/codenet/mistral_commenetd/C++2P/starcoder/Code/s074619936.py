# Start of code

# Initialize variables
str = ""
tmp = ""
sum = 0

# Start an infinite loop
while True:
    # Read a string from the user input
    str = input()

    # Check if the user wants to exit by entering "0"
    if str == "0":
        # Exit the loop if user enters "0"
        break

    # Initialize sum variable to zero
    sum = 0

    # Iterate through each character in the string
    for i in range(len(str)):
        # Get the character as a string
        tmp = str[i]

        # Convert the character to an integer and add it to the sum
        num = int(tmp)
        sum += num

    # Print the sum of the digits in the string
    print(sum)

# End of code
# 