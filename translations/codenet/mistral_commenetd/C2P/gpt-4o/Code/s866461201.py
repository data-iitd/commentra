# We include the standard input/output library

def main():  # The main function is the entry point of the program
    n = int(input())  # Read an integer value from the standard input and store it in the variable 'n'
    fd = [0] * 6  # An integer list named 'fd' of size 6, initialized with zeros
    for _ in range(n):  # Loop 'n' times
        height = float(input())  # Read a floating point value from the standard input and store it in the variable 'height'
        if height >= 185.0:
            fd[5] += 1  # If the height is greater than or equal to 185 cm, increment the sixth element of the 'fd' list
        elif height >= 180.0:
            fd[4] += 1  # Else if the height is greater than or equal to 180 cm, increment the fifth element of the 'fd' list
        elif height >= 175.0:
            fd[3] += 1  # Else if the height is greater than or equal to 175 cm, increment the fourth element of the 'fd' list
        elif height >= 170.0:
            fd[2] += 1  # Else if the height is greater than or equal to 170 cm, increment the third element of the 'fd' list
        elif height >= 165.0:
            fd[1] += 1  # Else if the height is greater than or equal to 165 cm, increment the second element of the 'fd' list
        else:
            fd[0] += 1  # Else, increment the first element of the 'fd' list

    for i in range(6):  # Iterate through the 'fd' list using a for loop
        print(f"{i + 1}:", end='')  # Print the index of the current element of the list followed by a colon
        print('*' * fd[i])  # Print a star for each occurrence
    return 0  # The main function returns zero to indicate successful execution

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
