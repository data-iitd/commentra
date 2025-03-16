package main

import (
	"fmt"
	"math"
)

func main() {
	var x1, y1, x2, y2 int
	fmt.Scan(&x1, &y1, &x2, &y2) // Read the coordinates

	if x1 == x2 { // Check if x1 and x2 are equal
		dif := int(math.Abs(float64(y1 - y2))) // Calculate the absolute difference between y1 and y2
		fmt.Printf("%d %d %d %d\n", x1+dif, y1, x1+dif, y2) // Print the result
	} else if y1 == y2 { // Check if y1 and y2 are equal
		dif := int(math.Abs(float64(x1 - x2))) // Calculate the absolute difference between x1 and x2
		fmt.Printf("%d %d %d %d\n", x1, y1+dif, x2, y2+dif) // Print the result
	} else if math.Abs(float64(x1-x2)) == math.Abs(float64(y1-y2)) { // Check if the absolute differences are equal
		fmt.Printf("%d %d %d %d\n", x1, y2, x2, y1) // Print the result
	} else { // If none of the above conditions are met
		fmt.Println(-1) // Print -1
	}
}

// <END-OF-CODE>
