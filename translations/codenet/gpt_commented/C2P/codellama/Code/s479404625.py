#include <stdio.h>
#include <string.h>

int main()
{
    # Declare character arrays to hold three strings
    A = input("Enter first string: ")
    B = input("Enter second string: ")
    C = input("Enter third string: ")

    # Calculate the lengths of the first two strings
    la = len(A)
    lb = len(B)

    # Check if the last character of A is the same as the first character of B
    # and if the last character of B is the same as the first character of C
    if A[la - 1] == B[0] and B[lb - 1] == C[0]:
        # If both conditions are true, print "YES"
        print("YES")
    else:
        # If either condition is false, print "NO"
        print("NO")

    return 0 # Indicate that the program ended successfully
}

