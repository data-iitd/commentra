def main():
    S = input()  # Read a string of six characters from the standard input

    for i in range(len(S) - 1):  # Iterate through each character in the string 'S'
        if S[i] == 'A' and S[i + 1] == 'C':  # Check if the current character is 'A' and the next character is 'C'
            print("Yes")  # If so, print 'Yes' to the standard output
            return

    print("No")  # If no pair of 'AC' is found, print 'No' to the standard output


main()  # Call the main function
