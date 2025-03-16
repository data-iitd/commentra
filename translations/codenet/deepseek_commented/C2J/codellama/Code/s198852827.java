#include<stdio.h>  // Include the standard input-output library

#define ABS(x) (((x)<(0))?(-(x)):(x))  // Define a macro to return the absolute value of a number

public class Main{  // Start of the main class
  public static void main(String[] args){  // Start of the main function
    int N,t,x,y,nx=0,ny=0,nt=0;  // Declare variables to store the values of N, t, x, y, and their initial positions nx, ny, and starting time nt
    int i,j,k,tmp;  // Declare loop counters
    scanf("%d",&N);  // Read the number of movements from the standard input
    for(i=0;i<N;i++){  // Start a loop that runs N times
      scanf("%d%d%d",&t,&x,&y);  // Read the time and coordinates for each movement
      tmp=t-nt-(ABS(x-nx)+ABS(y-ny));  // Calculate the difference between the required time and the actual time needed to reach the coordinates
      if(tmp<0 || tmp%2){  // Check if the difference is less than 0 or if it is odd
        System.out.println("No");  // Output "No" and terminate the program
        return;
      }
      nx=x;  // Update the current x-coordinate
      ny=y;  // Update the current y-coordinate
      nt=t;  // Update the current time
    }
    System.out.println("Yes");  // If the loop completes without issues, output "Yes"
  }
}
