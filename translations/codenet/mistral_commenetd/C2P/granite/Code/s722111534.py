
# We import the standard input/output library
import sys

# The main function is the starting point of the program
def main():
  # Declare variables
  hcell, wcell, hpaint, wpaint, nblack, nwhite = 0, 0, 0, 0, 0, 0

  # Declare and initialize variables for the height and width of the grid,
  # the number of rows and columns to be painted with black and white respectively

  hcell, wcell = map(int, sys.stdin.readline().split()) # Read the height and width of the grid from the user

  hpaint, wpaint = map(int, sys.stdin.readline().split()) # Read the number of rows and columns to be painted with black and white respectively

  nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint) # Calculate the number of black painted cells

  # Calculate the number of black painted cells by multiplying the number of columns and rows to be painted with black,
  # then multiplying the height and width of the grid and subtracting the product of the number of rows and columns to be painted with black and the number of columns and rows to be painted with white

  nwhite = (hcell*wcell) - nblack # Calculate the number of white unpainted cells

  # Calculate the number of white unpainted cells by subtracting the number of black painted cells from the total number of cells in the grid

  print(nwhite) # Print the number of white unpainted cells to the console

if __name__ == "__main__":
  main() # Call the main function

