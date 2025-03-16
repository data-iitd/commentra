
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
	// Read input values for lengths (a, b) and time (h, m)
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	inputSlice := strings.Split(input, ",")
	a, _ := strconv.Atoi(inputSlice[0])
	b, _ := strconv.Atoi(inputSlice[1])
	h, _ := strconv.Atoi(inputSlice[2])
	m, _ := strconv.Atoi(inputSlice[3])

	// Calculate the angle C between the hour and minute hands of the clock
	// The formula calculates the absolute difference in degrees
	C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))

	// If the angle is greater than 180 degrees, find the smaller angle
	if C > 180 {
		C = 360 - C
	}

	// Calculate the cosine of angle C in radians
	cosC := math.Cos(math.radians(C))

	// Use the Law of Cosines to calculate the length of the third side of the triangle
	// formed by the lengths a, b, and the angle C
	fmt.Println(math.Sqrt(float64(a*a+b*b-2*a*b*cosC)))
}
