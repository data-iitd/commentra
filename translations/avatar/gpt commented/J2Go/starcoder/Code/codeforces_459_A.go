package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the coordinates of the two points (x1, y1) and (x2, y2)
	x1, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	y1, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x2, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	y2, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Check if the two points are vertically aligned (same x-coordinate)
	if x1 == x2 {
		// Calculate the vertical distance between the two points
		dif := abs(y1 - y2)
		// Output the coordinates of the rectangle formed by the two points
		fmt.Println((x1 + dif), y1, (x1 + dif), y2)
	}
	// Check if the two points are horizontally aligned (same y-coordinate)
	else if y1 == y2 {
		// Calculate the horizontal distance between the two points
		dif := abs(x1 - x2)
		// Output the coordinates of the rectangle formed by the two points
		fmt.Println(x1, (y1 + dif), x2, (y2 + dif))
	}
	// Check if the two points form a square (equal distance in both x and y)
	else if abs(x1-x2) == abs(y1-y2) {
		// Output the coordinates of the rectangle formed by swapping y-coordinates
		fmt.Println(x1, y2, x2, y1)
	}
	// If none of the above conditions are met, output -1 indicating no rectangle can be formed
	else {
		fmt.Println(-1)
	}
}

// readLine reads a line from the given reader
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

// abs returns the absolute value of the given integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

