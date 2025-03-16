#include<stdio.h>  # Include the standard input/output library

def main():  # Define the main function, the entry point of the program
  hcell, wcell, hpaint, wpaint, nblack, nwhite = 0, 0, 0, 0, 0, 0  # Declare integer variables

  # Read the number of cells in the grid and the number of rows/columns to be painted
  hcell, wcell = input().split()
  hpaint, wpaint = input().split()

  # Calculate the number of black cells
  nblack = (int(wcell) * int(hpaint)) + (int(hcell) * int(wpaint)) - (int(hpaint) * int(wpaint))

  # Calculate the number of white cells
  nwhite = (int(hcell) * int(wcell)) - nblack

  # Print the number of white cells
  print(nwhite)

  return 0  # Return 0 to indicate successful execution

