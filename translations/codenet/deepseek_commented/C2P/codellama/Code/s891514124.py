#include <stdio.h>  # Include the standard input-output library

def main():  # Define the main function, which returns an integer

    S = int(input())  # Read an integer input from the user and store it in S

    # Check if S is less than 60
    if S < 60:
        print("0:0:%d" % S)  # Print "0:0:S" if S is less than 60

    # Check if S is less than 3600
    elif S < 3600:
        print("0:%d:%d" % (S // 60, S % 60))  # Print "0:S/60:S%60" if S is less than 3600

    # If S is not less than 3600
    else:
        print("%d:%d:%d" % (S // 3600, (S % 3600) // 60, (S % 60) % 60))  # Print "S/3600:S%3600/60:S%60" if S is not less than 3600

    return 0  # Return 0 to indicate successful execution


