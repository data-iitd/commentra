#include<stdio.h>  // Include the standard input/output library

public class Main {  // Define the main class
  public static void main(String[] args) {  // Define the main function, the entry point of the program
    int hcell, wcell, hpaint, wpaint, nblack, nwhite;  // Declare integer variables

    // Read the number of cells in the grid and the number of rows/columns to be painted
    scanf("%d %d", &hcell, &wcell);
    scanf("%d %d", &hpaint, &wpaint);

    // Calculate the number of black cells
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

    // Calculate the number of white cells
    nwhite = (hcell * wcell) - nblack;

    // Print the number of white cells
    printf("%d\n", nwhite);

    return 0;  // Return 0 to indicate successful execution
  }
}

