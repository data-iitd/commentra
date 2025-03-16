#include<stdio.h>  # Include the standard input-output library
a,b,c=map(int,input().split())  # Read three integer inputs from the user and store them in a, b, and c
if a<b and b<c:  # Check if a is less than b and b is less than c
    print("Yes")  # If true, print "Yes"
else:  # Otherwise
    print("No")  # Print "No"
