// Package main - where the program starts
package main

// Importing fmt for printing the output
import "fmt"

// Importing math for calculating the angles
import "math"

// Importing "sort" for sorting the list of thetas
import "sort"

// Function for reading input from the console
func readInput() (int, []int, []int) {
    // Reading the number of points (N) from the input
    var N int
    fmt.Scanf("%d", &N)

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    x := make([]int, N)
    y := make([]int, N)

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &x[i])
        fmt.Scanf("%d", &y[i])
    }

    return N, x, y
}

// Function for calculating the angles between each pair of points and storing them in a list called thetas
func calculateThetas(N int, x, y []int) []float64 {
    // Creating a new list for storing the angles
    thetas := make([]float64, 0)

    // Calculating the angles between the current point and all other points
    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            if i == j {
                continue
            }

            // Calculating the angle using the atan2 function
            thetas = append(thetas, math.Atan2(float64(y[j] - y[i]), float64(x[j] - x[i])))
        }
    }

    // Sorting the list of angles in ascending order
    sort.Float64s(thetas)

    // Adding the angle between the last point and the first point (wrapped around 2π) to the list
    thetas = append(thetas, thetas[0] + 2*math.Pi)

    return thetas
}

// Function for finding the maximum angle between consecutive angles and calculating the answer
func findAnswer(thetas []float64) float64 {
    // Finding the maximum angle between consecutive angles and calculating the answer
    ans := 0.0
    for k := 0; k < len(thetas) - 1; k++ {
        ans = math.Max(ans, thetas[k+1] - thetas[k] - math.Pi)
    }

    return ans / (2 * math.Pi)
}

// Main function
func main() {
    // Reading the number of points (N) from the input
    N, x, y := readInput()

    // Calculating the angles between each pair of points and storing them in a list called thetas
    thetas := calculateThetas(N, x, y)

    // Finding the maximum angle between consecutive angles and calculating the answer
    ans := findAnswer(thetas)

    // Printing the answer
    fmt.Printf("%.10f\n", ans)
}

