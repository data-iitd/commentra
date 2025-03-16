# Importing the necessary library for input
import sys

def main():
    # Reading the first line of input as a string
    str_input = input().strip()
    # Converting the string to a list of characters
    c = list(str_input)
    # Reading the second line of input as a long integer
    k = int(input().strip())
    n = len(str_input)  # Finding the length of the string

    for i in range(k):  # Starting a for loop to iterate through the character list up to the given limit 'k'
        if c[i] == '1':  # Checking if the current character is '1'
            if i == k - 1:  # Checking if the current index is the last index of the list
                print(1)  # If yes, print '1' and exit the function
                return
        else:
            print(c[i])  # If the current character is not '1', print it to the console
            return  # Exit the function as soon as a non-'1' character is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
