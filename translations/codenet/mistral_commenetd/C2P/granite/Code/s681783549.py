
S = input()  # Read a string of six characters from the user and store it in the variable 'S'

for i in range(len(S) - 1):  # Iterate through each character in the string 'S' except for the last one
    if S[i] == 'A' and S[i + 1] == 'C':  # Check if the current character is 'A' and the next character is 'C'
        print("Yes")  # If so, print 'Yes' to the standard output
        exit()  # And exit the program

print("No")  # If no pair of 'AC' is found, print 'No' to the standard output
