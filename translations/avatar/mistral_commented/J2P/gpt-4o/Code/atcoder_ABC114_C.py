# Importing the necessary module for user input
import sys

def main():
    N = gi()  # Getting the value of N from user input

    i = 357  # Initializing the variable i with a value of 357
    c = 0  # Initializing the variable c with a value of 0

    while i <= N:  # Starting a while loop that continues as long as i is less than or equal to N
        s = str(i)  # Converting the integer value of i to a string

        if '3' in s and '5' in s and '7' in s:  # Checking if the string contains the digits 3, 5, and 7
            c += 1  # Incrementing the value of c by 1 if the condition is true

        sb = []  # Creating a new list to build the new string
        f = False  # Initializing a boolean variable f with a value of false

        for j in range(len(s)):  # Starting a for loop that iterates through each character in the string s
            a = s[len(s) - 1 - j]  # Getting the character at the current index in reverse order

            if f:  # If the boolean variable f is true
                sb.append(a)  # Appending the current character to the list
            else:  # If the boolean variable f is false
                if a == '3':  # Checking if the current character is a 3
                    sb.append('5')  # If it is, append a 5 to the list and set f to true
                    f = True
                elif a == '5':  # Checking if the current character is a 5
                    sb.append('7')  # If it is, append a 7 to the list and set f to true
                    f = True
                else:  # If the current character is not a 3, 5, or 7, append a 3 to the list and set f to true
                    sb.append('3')
                    f = True

        if not f: 
            sb.append('3')  # If we have not found any 3, 5, or 7 in the string, append a 3 to the list

        i = int(''.join(reversed(sb)))  # Converting the reversed list back to an integer and assigning it to the variable i

    print(c)  # Printing the value of c to the console

def gs():  # Method for reading a single string input from the user
    return input()

def gi():  # Method for reading a single integer input from the user
    return int(input())

def gl():  # Method for reading a single long integer input from the user
    return int(input())

def gd():  # Method for reading a single double input from the user
    return float(input())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
