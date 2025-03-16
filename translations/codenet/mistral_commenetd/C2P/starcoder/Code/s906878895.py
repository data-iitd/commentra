#include<stdio.h> 
// This line includes the standard input/output library

def main():
    while True:
        a,b=map(int,input().split())
        if a==0 and b==0:
            break
        x=a+b
        # Add this comment to explain the assignment of the sum of a and b to x

        w=0
        # Initialize w to zero

        while x:
            w+=1
            # Increment w each time through the loop
            x//=10
            # Divide x by 10 to get the next digit
        print(w)
        # Print the value of w, which represents the number of digits in the sum of a and b

# The main function returns 0 to indicate successful execution

