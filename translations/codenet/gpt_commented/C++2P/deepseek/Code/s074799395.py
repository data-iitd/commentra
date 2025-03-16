def main():
    B = input()  # Read a character input from the user
    
    # Determine the output character based on the input character
    if B == 'A':
        OUT = 'T'  # If input is 'A', output 'T'
    elif B == 'T':
        OUT = 'A'  # If input is 'T', output 'A'
    elif B == 'C':
        OUT = 'G'  # If input is 'C', output 'G'
    else:
        OUT = 'C'  # For any other input, output 'C'
    
    # Output the result to the console
    print(OUT)

main()  # Call the main function

