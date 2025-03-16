// Importing necessary Go utility classes
import (
	"fmt"
	"math"
	"sort"
)

// Main method where the program starts
func main() {
	// Creating a Scanner object for reading input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Reading the number of points (N) from the input
	var N int
	scan.Scan()
	fmt.Sscan(scan.Text(), &N)

	// Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
	x := make([]int, N)
	y := make([]int, N)

	// Reading the x and y coordinates of each point and storing them in the respective arrays
	for i := 0; i < N; i++ {
		scan.Scan()
		fmt.Sscan(scan.Text(), &x[i], &y[i])
	}

	// Calculating the angles between each pair of points and storing them in a list called thetas
	thetas := make([]float64, N)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i == j {
				continue
			}

			// Calculating the angle using the atan2 function
			thetas[j] = math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i]))
		}

		// Sorting the list of angles in ascending order
		sort.Float64s(thetas)

		// Adding the angle between the last point and the first point (wrapped around 2π) to the list
		thetas = append(thetas, thetas[0]+2*math.Pi)
	}

	// Finding the maximum angle between consecutive angles and calculating the answer
	ans := 0.0
	for k := 0; k < N-1; k++ {
		ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
	}

	// Printing the answer
	fmt.Println(ans / (math.Pi * 2))
}

