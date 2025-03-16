

# Read two integers from the standard input and store them in the sheep and wolf variables
sheep, wolf = map(int, input().split())

# Check if the number of wolves is greater than or equal to the number of sheep
if wolf >= sheep:
    # If the condition is true, print the message "unsafe" to the standard output
    print("unsafe")
else:
    # If the condition is false, print the message "safe" to the standard output
    print("safe")

# End the program by indicating successful execution
print("