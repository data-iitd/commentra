def cout(str):
    print(str)  # Printing the given String to the console

def main():
    n = int(input())  # Reading an integer value from the console and assigning it to the variable n
    str = input()  # Reading a line of text from the console and assigning it to the variable str

    a = ""  # Declaring an empty String variable a

    for i in range(n // 2):  # Starting a for loop that iterates n/2 times
        a += str[i]  # Appending the character at the current index of str to the variable a

    if str == a + a:  # Checking if the given string is a palindrome
        cout("Yes")  # Printing "Yes" to the console if the given string is a palindrome
    else:
        cout("No")  # Printing "No" to the console if the given string is not a palindrome

if __name__ == "__main__":
    main()  # Calling the main function to execute the program

# <END-OF-CODE>
