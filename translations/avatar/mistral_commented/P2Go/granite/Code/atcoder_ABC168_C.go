
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Assign values to variables a, b, h, and m using the bufio.Scanner and strings.Split functions
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	h, _ := strconv.Atoi(parts[2])
	m, _ := strconv.Atoi(parts[3])

	// Calculate the angle C between hour hand and minute hand
	C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))
	if C > 180 {
		// If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
		C = 360 - C
	}

	// Calculate the cosine of angle C
	cosC := math.Cos(math.Pi * C / 180)

	// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
	fmt.Println(math.Sqrt(float64(a*a+b*b-2*a*b*cosC)))
}

