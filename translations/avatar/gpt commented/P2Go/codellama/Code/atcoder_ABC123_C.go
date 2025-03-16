// Import necessary libraries
import (
	"fmt"
	"math"
)

// Read an integer input from the user
var N int
fmt.Scan(&N)

// Read 5 integer inputs from the user and store them in a list A
var A []int
for i := 0; i < 5; i++ {
	var a int
	fmt.Scan(&a)
	A = append(A, a)
}

// Calculate the minimum value from the list A, divide N by this minimum value,
// take the ceiling of the result, and add 4 to it before printing the final result
fmt.Println(math.Ceil(float64(N)/float64(min(A))) + 4)

// 