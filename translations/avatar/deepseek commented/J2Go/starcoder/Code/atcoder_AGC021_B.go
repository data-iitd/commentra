
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Read the number of points N from the input.
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Step 2: Read the coordinates of each point and store them in arrays x and y.
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Step 3: For each point, calculate the angles between this point and all other points.
	for i := 0; i < N; i++ {
		thetas := make([]float64, 0)
		for j := 0; j < N; j++ {
			if i == j {
				continue
			}
			// Calculate the angle using atan2
			thetas = append(thetas, math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i])))
		}

		// Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
		sort.Float64s(thetas)
		thetas = append(thetas, thetas[0]+2*math.Pi)

		// Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
		ans := 0.0
		for k := 0; k < len(thetas)-1; k++ {
			ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
		}

		// Step 6: Print the result.
		fmt.Printf("%.16f\n", ans/(math.Pi*2))
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

