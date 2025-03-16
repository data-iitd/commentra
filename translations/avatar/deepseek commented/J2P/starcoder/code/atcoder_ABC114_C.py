import sys; # Importing the sys module for input

def main():
    N = int(sys.stdin.readline()) # Reading an integer N from the user
    i = 357 # Initializing the starting number
    c = 0 # Initializing the counter for valid numbers

    # Main loop to find numbers containing '3', '5', and '7'
    while i <= N:
        s = str(i) # Converting the current number to a string
        if '3' in s and '5' in s and '7' in s:
            c += 1 # Incrementing the counter if all required digits are present

        # Building a new number by replacing the last digit
        sb = ''
        f = False
        for a in s[::-1]:
            if f:
                sb += a # Appending characters after the replacement
            else:
                if a == '3':
                    sb += '5' # Replacing '3' with '5'
                    f = True
                elif a == '5':
                    sb += '7' # Replacing '5' with '7'
                    f = True
                else:
                    sb += '3' # Replacing other digits with '3'
        if not f: sb += '3' # Appending '3' if no replacements were made

        # Reversing the new number and converting it back to a long
        sb2 = sb[::-1]
        i = int(sb2)

    # Output the result
    print(c) # Printing the count of valid numbers

if __name__ == "__main__":
    main()

