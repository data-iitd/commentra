
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
	// Step 1: Reading Input
	// The code reads the number of points N and the coordinates of the points XY from the standard input.
	N, _ := strconv.Atoi(read())
	XY := make([][]float64, N)
	for i := 0; i < N; i++ {
		xy := strings.Split(read(), " ")
		x, _ := strconv.ParseFloat(xy[0], 64)
		y, _ := strconv.ParseFloat(xy[1], 64)
		XY[i] = []float64{x, y}
	}

	// Step 2: Processing Coordinates
	// The coordinates are grouped into pairs and stored in the list XY.
	// (Not needed in Go)

	// Step 3: Calculating Angles
	// For each point, the code calculates the angles to all other points using atan2.
	D := make([]float64, N)
	for i, xy := range XY {
		x, y := xy[0], xy[1]
		for j, xy2 := range XY {
			if i == j {
				continue
			}
			x2, y2 := xy2[0], xy2[1]
			D[i] = math.Atan2(y2-y, x2-x)
		}
	}

	// Step 4: Handling Circular Angles
	// The angles are adjusted to handle the circular nature of angles (0 to 2π).
	D = append(D, D[0]+2*math.Pi)

	// Step 5: Finding the Maximum Gap
	ans := 0.0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N+1; j++ {
			if D[j]-D[i] >= math.Pi {
				ans = math.Max(ans, D[j]-D[i]-math.Pi)
			}
		}
	}

	// Step 6: Calculating the Fraction
	// The fraction of the circle covered by the maximum gap is calculated and printed.
	fmt.Println(ans / (2 * math.Pi))
}

func read() string {
	result := ""
	buf := make([]byte, 0)
	for {
		line, prefix, err := bufio.NewReader(os.Stdin).ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if prefix == false {
			break
		}
	}
	result = string(buf)
	return result
}

