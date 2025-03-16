def main():
    # Read the input string from standard input
    s = input().strip()
    # Get the length of the input string
    l = len(s)
    # Initialize the answer as "AC" (Accepted)
    ans = "AC"
    
    # Check if the first character is 'A'
    if s[0] != 'A':
        # If not, set the answer to "WA" (Wrong Answer)
        ans = "WA"
    
    # Initialize a counter for uppercase letters
    cnt = 0
    # Loop through the string starting from the second character
    for i in range(1, l):
        # Check if the current character is an uppercase letter
        if s[i].isupper():
            # Check if the uppercase letter is not at the second or last position
            # or if it is not 'C'
            if i == 1 or i == l - 1 or s[i] != 'C':
                # If any of the conditions are met, set the answer to "WA"
                ans = "WA"
            # Increment the uppercase letter counter
            cnt += 1
    
    # Check if there is exactly one uppercase letter (which should be 'C')
    if cnt != 1:
        # If not, set the answer to "WA"
        ans = "WA"
    
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
