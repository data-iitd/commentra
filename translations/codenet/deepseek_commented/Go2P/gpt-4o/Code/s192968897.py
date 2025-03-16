def main():
    s = input()  # Read input from the user
    l = len(s)   # Calculate the length of the string and store it in l
    ans = "AC"   # Initialize the answer variable with "AC"

    # Check if the first character is 'A'
    if s[0] != 'A':
        ans = "WA"  # If the first character is not 'A', set ans to "WA"

    cnt = 0  # Initialize a counter to keep track of uppercase letters
    for i in range(1, l):  # Iterate over the string starting from the second character
        if s[i].isupper():  # Check if the character is an uppercase letter
            if i == 1 or i == l - 1 or s[i] != 'C':  # Check if the character is 'C' or not at the second or second-to-last position
                ans = "WA"  # If any of the conditions are met, set ans to "WA"
            cnt += 1  # Increment the counter if the conditions are met

    # Check if there is exactly one uppercase letter that is not the first or last character and is 'C'
    if cnt != 1:
        ans = "WA"  # If cnt is not 1, set ans to "WA"

    print(ans)  # Print the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
