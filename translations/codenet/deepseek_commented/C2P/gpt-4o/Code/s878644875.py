# Include necessary headers for input and output

def main():  # Define the main function
    s = input()  # Read the first string from the user
    t = input()  # Read the second string from the user
    hit = 0  # Initialize a counter for hits
    for i in range(3):  # Compare characters in the strings
        if s[i] == t[i]:  # Increment the hit counter if characters match
            hit += 1
    print(hit)  # Print the number of matching characters

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
