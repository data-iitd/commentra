def main():
    # Read a long integer value from the user
    a = int(input())
    
    # Read a string value from the user
    b = input()
    
    # Convert the string to a character array for processing
    b_char = list(b)
    
    # Initialize an empty string to build the integer representation
    b_str = ""
    
    # Loop through each character in the character array
    for char in b_char:
        # If the character is not a '.', append it to b_str
        if char != '.':
            b_str += char
    
    # Convert the built string (b_str) to an integer
    b_int = int(b_str)
    
    # Calculate the result by multiplying 'a' with 'b_int' and dividing by 100
    result = (a * b_int) // 100
    
    # Print the result to the console
    print(result)

if __name__ == "__main__":
    main()
