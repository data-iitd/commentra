#include<stdio.h>

int main() {
    # Declare variables for cell dimensions and paint dimensions
    hcell, wcell, hpaint, wpaint, nblack, nwhite = 0, 0, 0, 0, 0, 0

    # Input the dimensions of the grid (number of cells in height and width)
    # 順にマス行、マス列
    hcell, wcell = input().split()

    # Input the dimensions of the paint area (height and width of the painted area)
    # 塗る行、塗る列
    hpaint, wpaint = input().split()

    # Calculate the number of black cells painted
    # nblack = (width of the cells * height of the painted area) + (height of the cells * width of the painted area) - (area of the painted area)
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

    # Calculate the number of white cells remaining
    # Total cells - painted black cells
    nwhite = (hcell * wcell) - nblack

    # Output the number of white cells
    print(nwhite)

    return 0 # End of the program
}
