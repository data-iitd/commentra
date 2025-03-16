def main():
    # Read the input string from standard input
    s = input()
    
    # Calculate the difference between lowercase and uppercase letters
    d = ord('a') - ord('A')
    
    # Initialize an empty string to hold the modified characters
    result = ""
    
    # Iterate over each character in the input string
    for r in s:
        # Initialize a variable to hold the modified character
        rr = r
        
        # Check if the character is an uppercase letter
        if 'A' <= r <= 'Z':
            # Convert uppercase to lowercase by adding the difference
            rr = chr(ord(r) + d)
        elif 'a' <= r <= 'z':
            # Convert lowercase to uppercase by subtracting the difference
            rr = chr(ord(r) - d)
        
        # Append the modified character to the result
        result += rr
    
    # Print the final result
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
