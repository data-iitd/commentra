
```python
# Python program to check if two strings have matching characters

# Importing the utility package for using Scanner
import sys

# Initializing an array to hold 4 strings
str = [""] * 4

# Loop to read 4 strings from user input
for i in range(4):
    str[i] = input()

# Flags to indicate if a condition is met
yes = 0

# Loop to iterate through the first 3 strings
for u in range(2):
    for i in range(2):
        # Check if the characters in the strings meet the specified conditions
        if ((str[u][i] == str[u][i + 1] and 
            (str[u + 1][i] == str[u][i] or 
             str[u + 1][i + 1] == str[u][i])) or 
            (str[u + 1][i] == str[u + 1][i + 1] and 
            (str[u][i] == str[u + 1][i] or 
             str[u][i + 1] == str[u + 1][i]))) :
            
            yes = 1 # Set flag to indicate a match was found
            print("YES") # Output "YES"
            break # Exit the inner loop
    # If a match was found, exit the outer loop
    if yes == 1:
        break

# If no matches were found, output "NO"
if yes == 0:
    print("NO")
```
