package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the standard input
	in := bufio.NewScanner(os.Stdin)

	// Create a PrintWriter object to output results to the standard output
	pw := bufio.NewWriter(os.Stdout)

	// Read the coordinates of the two points (x1, y1) and (x2, y2)
	var x1, y1, x2, y2 int
	in.Scan(&x1, &y1, &x2, &y2)

	// Check if the two points are vertically aligned (same x-coordinate)
	if x1 == x2 {
		// Calculate the vertical distance between the two points
		dif := math.Abs(float64(y1 - y2))
		// Output the coordinates of the rectangle formed by the two points
		fmt.Fprintln(pw, x1+int(dif), y1, x1+int(dif), y2)
	} else if y1 == y2 {
		// Calculate the horizontal distance between the two points
		dif := math.Abs(float64(x1 - x2))
		// Output the coordinates of the rectangle formed by the two points
		fmt.Fprintln(pw, x1, y1+int(dif), x2, y2+int(dif))
	} else if math.Abs(float64(x1-x2)) == math.Abs(float64(y1-y2)) {
		// Output the coordinates of the rectangle formed by swapping y-coordinates
		fmt.Fprintln(pw, x1, y2, x2, y1)
	} else {
		// If none of the above conditions are met, output -1 indicating no rectangle can be formed
		fmt.Fprintln(pw, -1)
	}

	// Close the PrintWriter to flush the output
	pw.Flush()
}

// Debugging utility method to print objects to the error output
func debug(obj ...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// END-OF-CODE
