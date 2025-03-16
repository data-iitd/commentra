package main

import (
    "fmt"
)

func main() {
    // Declare variables to hold the dimensions and calculated values
    var a, b, mawari, menseki int

    // Read two integer inputs from the user representing the dimensions
    fmt.Scanf("%d %d", &a, &b)

    // Calculate the perimeter (mawari) of the rectangle
    mawari = 2 * (a + b) // Perimeter formula: 2 * (length + width)

    // Calculate the area (menseki) of the rectangle
    menseki = a * b // Area formula: length * width

    // Print the area and perimeter to the console
    fmt.Printf("%d %d\n", menseki, mawari)
}

// <END-OF-CODE>
