package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for cell dimensions and paint dimensions
    var hcell, wcell, hpaint, wpaint, nblack, nwhite int

    // Input the dimensions of the grid (number of cells in height and width)
    // 順にマス行、マス列
    fmt.Scanf("%d %d", &hcell, &wcell)

    // Input the dimensions of the paint area (height and width of the painted area)
    // 塗る行、塗る列
    fmt.Scanf("%d %d", &hpaint, &wpaint)

    // Calculate the number of black cells painted
    // nblack = (width of the cells * height of the painted area) + (height of the cells * width of the painted area) - (area of the painted area)
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

    // Calculate the number of white cells remaining
    // Total cells - painted black cells
    nwhite = (hcell * wcell) - nblack

    // Output the number of white cells
    fmt.Printf("%d\n", nwhite)
}

