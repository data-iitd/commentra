
package main

import "fmt"

func main() {
    var a, b, mawari, menseki int

    // Read two integer inputs from the user representing the dimensions
    fmt.Scan(&a, &b)

    // Calculate the perimeter (mawari) of the rectangle
    mawari = a + a + b + b // Perimeter formula: 2 * (length + width)

    // Calculate the area (menseki) of the rectangle
    menseki = a * b // Area formula: length * width

    // Print the area and perimeter to the console
    fmt.Printf("%d %d\n", menseki, mawari)
}

// END-OF-CODE