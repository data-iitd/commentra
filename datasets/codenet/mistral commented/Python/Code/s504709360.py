
s = input("Take a string as input from the user.")
if len(s) < 26: # Check if the length of the string is less than 26.
    for i in range(26): # Iterate through all the alphabets.
        c = chr(ord("a") + i) # Get the next alphabet character.
        if c not in s: # Check if the character is not already present in the string.
            print(s + c) # If not, print the string with the new character and exit.
            exit() # Exit the loop and the function.
else: # If the length of the string is greater than or equal to 26.
    for i in reversed(range(1, 26)): # Iterate through the string in reverse order from the second character to the last.
        if s[i - 1] < s[i]: # Check if the previous character is smaller than the current character.
            s1 = s[0:i - 1] # Create a substring from the beginning of the string up to the previous character.
            for j in range(26): # Iterate through all the alphabets.
                c = chr(ord("a") + j) # Get the next alphabet character.
                if c > s[i - 1] and c not in s1: # Check if the character is greater than the previous character and not already present in the substring.
                    print(s1 + c) # If yes, print the substring with the new character and exit.
                    exit() # Exit the loop and the function.
    print(-1) # If no such character is found, print -1.