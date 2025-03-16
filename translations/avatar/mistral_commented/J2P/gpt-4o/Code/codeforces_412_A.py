# Importing the sys module for user input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the first integer input from the user
    k = int(sys.stdin.readline().strip())  # Reading the second integer input from the user
    a = sys.stdin.readline().strip()        # Reading the string input from the user

    if k > n / 2:                          # Check if k is greater than n/2
        while k < n:                       # If true, print "RIGHT" until k equals n
            print("RIGHT")
            k += 1
    else:                                  # Else if k is less than or equal to n/2
        while k > 1:                       # Print "LEFT" until k equals 1
            print("LEFT")
            k -= 1

    if k == 1:                             # If k equals 1
        for i in range(len(a)):            # Iterate through each character in the string
            print("PRINT " + a[i])         # Print the character
            if (i + 1) < len(a):           # If the index is not the last one
                print("RIGHT")              # Print "RIGHT"
    else:                                  # Else if k is not equal to 1
        for i in range(len(a) - 1, -1, -1): # Iterate through each character in reverse order
            print("PRINT " + a[i])         # Print the character
            if (i - 1) >= 0:               # If the index is not the first one
                print("LEFT")               # Print "LEFT"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
