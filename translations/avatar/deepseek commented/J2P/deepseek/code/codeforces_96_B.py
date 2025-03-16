def main():
    # Read a long integer input from the user
    number = int(input())
    
    # Initialize two variables, ans and value, to -1 and 0, respectively
    ans = -1
    value = 0
    
    # Set a mask variable to 2
    mask = 2
    
    # The code enters a while loop that continues as long as value is less than the input number
    while value < number:
        # Convert the mask value to a binary string, remove the first character, and store the result in the s variable
        s = bin(mask)[2:]
        mask += 1
        
        # Count the number of zeros in the binary string and store it in the zeros variable
        zeros = s.count('0')
        
        # If the number of zeros is not equal to the number of ones, skip the rest of the loop
        if zeros != len(s) - zeros:
            continue
        
        # Replace all zeros with 4 and all ones with 7 in the binary string and convert it back to a long integer
        s = s.replace('0', '4')
        s = s.replace('1', '7')
        value = int(s)
    
    # Print the value variable
    print(value)

main()
