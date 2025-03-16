

s = input() # Read a string from the standard input and store it in the variable's'

for j in range(len(s)): # Iterate through each character in the string's' using index 'j'
    for i in range(len(s)): # Nested loop to compare each character with all other characters in the string
        if (i!= j) and (s[i] == s[j]): # Check if the current characters at indices 'i' and 'j' are the same and not the same index
            print("no") # If duplicate characters are found, print 'no' and exit the program
            exit(0) # Exit the program with a successful return status

print("yes") # If no duplicate characters are found, print 'yes'

# 