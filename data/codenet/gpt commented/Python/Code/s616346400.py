def atc_079a(input_value: str) -> str:
    # Define the length of the substring to check for repetition
    n = 3
    
    # Iterate through the input string, stopping n characters before the end
    for i in range(0, len(input_value) + 1 - n):
        # Check for repeated characters in the substring of length n
        for j in range(1, n):
            # If the current character is not equal to the next character in the substring
            if input_value[i] != input_value[i + j]:
                break  # Exit the inner loop if characters differ
            
            # If we have checked all characters in the substring and they are the same
            if j == n - 1:
                return "Yes"  # Return "Yes" if a repeated substring is found
    
    # Return "No" if no repeated substring of length n is found
    return "No"


# Take input from the user
input_value = input()

# Call the function and print the result
print(atc_079a(input_value))
