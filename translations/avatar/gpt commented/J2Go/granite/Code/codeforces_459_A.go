
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner object to read input from the standard input
	in := bufio.NewReader(os.Stdin)

	// Create a scanner object to read input from the standard input
	out := bufio.NewWriter(os.Stdout)

	// Read the coordinates of the two points (x1, y1) and (x2, y2)
	line, _ := in.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	x1, _ := strconv.Atoi(parts[0])
	y1, _ := strconv.Atoi(parts[1])
	x2, _ := strconv.Atoi(parts[2])
	y2, _ := strconv.Atoi(parts[3])

	// Check if the two points are vertically aligned (same x-coordinate)
	if x1 == x2 {
		// Calculate the vertical distance between the two points
		dif := int(math.Abs(float64(y1 - y2)))
		// Output the coordinates of the rectangle formed by the two points
		out.WriteString(strconv.Itoa(x1+dif) + " " + strconv.Itoa(y1) + " " + strconv.Itoa(x1+dif) + " " + strconv.Itoa(y2) + "\n")
	}
	// Check if the two points are horizontally aligned (same y-coordinate)
	else if y1 == y2 {
		// Calculate the horizontal distance between the two points
		dif := int(math.Abs(float64(x1 - x2)))
		// Output the coordinates of the rectangle formed by the two points
		out.WriteString(strconv.Itoa(x1) + " " + strconv.Itoa(y1+dif) + " " + strconv.Itoa(x2) + " " + strconv.Itoa(y2+dif) + "\n")
	}
	// Check if the two points form a square (equal distance in both x and y)
	else if int(math.Abs(float64(x1 - x2))) == int(math.Abs(float64(y1 - y2))) {
		// Output the coordinates of the rectangle formed by swapping y-coordinates
		out.WriteString(strconv.Itoa(x1) + " " + strconv.Itoa(y2) + " " + strconv.Itoa(x2) + " " + strconv.Itoa(y1) + "\n")
	}
	// If none of the above conditions are met, output -1 indicating no rectangle can be formed
	else {
		out.WriteString("-1\n")
	}

	// Close the scanner to flush the output
	out.Flush()
}

// Debugging utility method to print objects to the error output
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// END-OF-CODE