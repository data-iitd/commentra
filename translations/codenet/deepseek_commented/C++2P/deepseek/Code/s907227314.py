def main():
    s = input()  # Read input from the user and store it in the string variable 's'
    a, z = -1, -1  # Initialize the positions of 'A' and 'Z' to -1 (indicating not found)

    # Iterate through the string to find the position of the first occurrence of 'A'
    for i in range(len(s)):
        if s[i] == 'A':
            a = i  # Assign the position of 'A' to variable 'a' and break the loop
            break

    # Iterate through the string in reverse to find the position of the last occurrence of 'Z'
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'Z':
            z = i  # Assign the position of 'Z' to variable 'z' and break the loop
            break

    # Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    print(z - a + 1)


main()  # Call the main function to execute the program

