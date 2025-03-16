#include<stdio.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables for cell dimensions and paint dimensions
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;

        // Input the dimensions of the grid (number of cells in height and width)
        // 順にマス行、マス列
        scanf("%d %d", &hcell, &wcell);

        // Input the dimensions of the paint area (height and width of the painted area)
        // 塗る行、塗る列
        scanf("%d %d", &hpaint, &wpaint);

        // Calculate the number of black cells painted
        // nblack = (width of the cells * height of the painted area) + (height of the cells * width of the painted area) - (area of the painted area)
        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

        // Calculate the number of white cells remaining
        // Total cells - painted black cells
        nwhite = (hcell * wcell) - nblack;

        // Output the number of white cells
        printf("%d\n", nwhite);

        return 0; // End of the program
    }
}

