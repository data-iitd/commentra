

import sys

def main():
    # Declaring static variables for sys.stdin and sys.stdout
    input = sys.stdin.readline
    print = sys.stdout.write

    K = int(input()) # Reading the input value of K

    # Checking if K is even or multiple of 5, returning -1 if true
    if K % 2 == 0 or K % 5 == 0: print('-1\n')

    # If K is multiple of 7, dividing it by 7 and multiplying it by 9
    if K % 7 == 0: K //= 7
    K *= 9

    # Initializing the answer variable and the remainder variable
    ans = 1
    remainder = 10 % K

    # Using a while loop to find the answer
    while remainder!= 1:
        ans += 1 # Incrementing the answer variable
        remainder = (remainder * 10) % K # Updating the remainder variable

    # Printing the answer
    print(str(ans) + '\n')

if __name__ == '__main__':
    main()

These comments should help make the code more readable and understandable for anyone who reads it.

