#include<stdio.h>

def main():
    hcell, wcell, hpaint, wpaint, nblack, nwhite = 0, 0, 0, 0, 0, 0
    # Declare variables

    hcell, wcell = map(int, input().split())
    # Read the height and width of the grid from the user

    hpaint, wpaint = map(int, input().split())
    # Read the number of rows and columns to be painted with black and white respectively

    nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)
    # Calculate the number of black painted cells

    nwhite = (hcell*wcell) - nblack
    # Calculate the number of white unpainted cells

    print(nwhite)
    # Print the number of white unpainted cells to the console

if __name__ == "__main__":
    main()

