// Import the math package and specifically the Atan2 function and Pi constant
import (
	"math"
)

// Read the input from standard input and parse it into two variables: N (number of points) and XY (a list of tuples representing the coordinates of N points)
var N int
var XY [][]int
fmt.Scan(&N)
XY = make([][]int, N)
for i := 0; i < N; i++ {
	XY[i] = make([]int, 2)
	fmt.Scan(&XY[i][0], &XY[i][1])
}

// Transpose the XY list so that it becomes a list of lists, where each inner list contains the x and y coordinates of a point
for i := 0; i < N; i++ {
	for j := 0; j < 2; j++ {
		XY[j][i] = XY[i][j]
	}
}

// Iterate through each point in XY and calculate the angles between it and all other points
for i := 0; i < N; i++ {
	// Calculate the differences between the x and y coordinates of the current point and all other points
	D := make([]float64, N)
	for j := 0; j < N; j++ {
		if j != i {
			D[j] = math.Atan2(float64(XY[0][j]-XY[0][i]), float64(XY[1][j]-XY[1][i]))
		}
	}

	// Append the angle between the current point and the first point (wrapped around if it's greater than pi)
	D = append(D, D[0]+2*math.Pi)

	// Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
	for j := 0; j < N; j++ {
		// If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
		if D[j+1]-D[j] >= math.Pi {
			ans += (D[j+1] - D[j]) - math.Pi
		}
	}
}

// Print the answer, which is the total area of the sectors divided by the total possible area (2π)
fmt.Println(ans / (2 * math.Pi))

