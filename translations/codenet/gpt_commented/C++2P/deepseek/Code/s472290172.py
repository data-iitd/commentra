def main():
    # Read input string from the user
    str = input()
    
    # Initialize variables to track the maximum length of valid characters and the current count
    max_length = 0
    current_count = 0
    
    # Iterate through each character in the input string
    for char in str:
        # Check if the character is one of the valid DNA bases
        if char in 'ACGT':
            # Increment the count for consecutive valid characters
            current_count += 1
        else:
            # Reset the count if an invalid character is encountered
            current_count = 0
        
        # Update the maximum length if the current count exceeds the previous maximum
        max_length = max(max_length, current_count)
    
    # Output the maximum length of consecutive valid characters found
    print(max_length)

main()
