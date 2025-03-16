#include<stdio.h>  # Include the standard input-output library

#define ABS(x) (((x)<(0))?(-(x)):(x))  # Define a macro to return the absolute value of a number

def main():  # Start of the main function
  N=int(input())  # Read the number of movements from the standard input
  for i in range(N):  # Start a loop that runs N times
    t,x,y=map(int,input().split())  # Read the time and coordinates for each movement
    tmp=t-nt-(ABS(x-nx)+ABS(y-ny))  # Calculate the difference between the required time and the actual time needed to reach the coordinates
    if(tmp<0 or tmp%2):  # Check if the difference is less than 0 or if it is odd
      print("No")  # Output "No" and terminate the program
      return 0
    nx=x  # Update the current x-coordinate
    ny=y  # Update the current y-coordinate
    nt=t  # Update the current time
  print("Yes")  # If the loop completes without issues, output "Yes"
  return 0

main()  # Call the main function

