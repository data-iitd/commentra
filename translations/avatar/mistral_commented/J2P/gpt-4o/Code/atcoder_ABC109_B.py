# Importing necessary modules
from collections import defaultdict

def main():
    N = int(input())  # Reading the number of strings from the input

    strings = {}  # Creating an empty dictionary to store strings

    for i in range(N):  # Loop to read strings from the input and store them in the dictionary
        strings[i] = input()

    ans = True  # Initializing a boolean variable to store the result of the check
    past = {}  # Creating an empty dictionary to store the previous strings
    next_char = ""  # Initializing a string variable to store the next character of the current string

    for i in range(N):  # Loop to check for the condition
        if strings[i] in past.values():  # Checking if the current string is already in the dictionary
            ans = False
            break
        past[i] = strings[i]  # Storing the current string in the dictionary

        if i != 0:  # Checking if it's not the first iteration of the loop
            if next_char != strings[i][0]:  # Checking if the current string starts with the same character as the previous string
                ans = False
                break

        next_char = strings[i][-1]  # Storing the last character of the current string in the next_char variable

    if ans:  # Printing "Yes" if the condition is satisfied
        print("Yes")
    else:  # Printing "No" if the condition is not satisfied
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
