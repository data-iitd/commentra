// Importing the math module for calculating the square root
import "math"

// Taking the number of points, n, and the number of dimensions, d, as input
var n, d int
fmt.Scanf("%d %d", &n, &d)

// Initializing a list 'points' of size 'n' to store the coordinates of each point
var points = make([][]int, n)

// Defining a function 'dist' to calculate the Euclidean distance between two points
func dist(x, y []int) float64 {
    // Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
    tmp := 0.0

    // Iterating through each dimension 'i' from 0 to 'd'
    for i := 0; i < d; i++ {
        // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
        tmp += (float64(x[i]) - float64(y[i])) * (float64(x[i]) - float64(y[i]))
    }

    // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
    return math.Sqrt(tmp)
}

// Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
var count int

// Iterating through each point 'i' in 'points'
for i, elm := range points {
    // Iterating through each point 'j' from 'i+1' to the last point in 'points'
    for j := i + 1; j < n; j++ {
        // Checking if the Euclidean distance between 'elm' and 'points[j]' is an integer
        if dist(elm, points[j]) == float64(int(dist(elm, points[j]))) {
            // Incrementing the 'count' variable if the condition is true
            count++
        }
    }
}

// Printing the final value of 'count'
fmt.Println(count)

