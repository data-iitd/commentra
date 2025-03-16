# Importing the necessary module for input
import sys

def main():
    N = int(input())  # Reading an integer N from the user
    i = 357  # Initializing the starting number
    c = 0  # Initializing the counter for valid numbers

    # Main loop to find numbers containing '3', '5', and '7'
    while i <= N:
        s = str(i)  # Converting the current number to a string
        if '3' in s and '5' in s and '7' in s:
            c += 1  # Incrementing the counter if all required digits are present

        # Building a new number by replacing the last digit
        sb = []
        f = False
        for j in range(len(s)):
            a = s[len(s) - 1 - j]
            if f:
                sb.append(a)  # Appending characters after the replacement
            else:
                if a == '3':
                    sb.append('5')  # Replacing '3' with '5'
                    f = True
                elif a == '5':
                    sb.append('7')  # Replacing '5' with '7'
                    f = True
                else:
                    sb.append('3')  # Replacing other digits with '3'
        if not f:
            sb.append('3')  # Appending '3' if no replacements were made

        # Reversing the new number and converting it back to an integer
        i = int(''.join(reversed(sb)))

    # Output the result
    print(c)  # Printing the count of valid numbers

if __name__ == "__main__":
    main()

# <END-OF-CODE>
