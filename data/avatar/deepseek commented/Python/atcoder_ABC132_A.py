
S = input()  # Take a string input from the user
from collections import Counter  # Import the Counter function from the collections module
c = Counter(S)  # Count the frequency of each character in the string S
Sa = set(list(S))  # Convert the string S into a set of unique characters

# Check if the number of unique characters is not equal to 2
if len(Sa) != 2:
    print("No")  # Print "No" and exit if the condition is true
    exit()  # Exit the program

# Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
for i in Sa:
    if c[i] != 2:
        print("No")  # Print "No" and exit if the condition is true
        exit()  # Exit the program

print("Yes")  # Print "Yes" if all characters have a frequency of 2

