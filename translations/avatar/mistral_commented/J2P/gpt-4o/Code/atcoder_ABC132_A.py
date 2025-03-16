from collections import defaultdict  # Importing defaultdict for storing character and their frequency

def main():
    s = input()  # Reading a string input from user
    map = defaultdict(int)  # Creating a defaultdict to store character and their frequency

    for currentChar in s:  # Iterating through each character in the string
        map[currentChar] += 1  # Incrementing the frequency of the current character in the defaultdict

    ok = True  # Initializing a boolean variable to check if all characters have frequency 2 or not

    for value in map.values():  # Iterating through the frequency values in the defaultdict
        if value != 2:  # Checking if the frequency of the current character is not 2
            ok = False  # Setting the boolean variable to false if any character has frequency other than 2
            break  # Exiting the loop if any character has frequency other than 2

    if ok and len(map) == 2:  # Checking if all characters have frequency 2 and the size of the defaultdict is 2
        print("Yes")  # Printing "Yes" if both conditions are true
    else:
        print("No")  # Printing "No" if any character has frequency other than 2 or the size of the defaultdict is not 2

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
