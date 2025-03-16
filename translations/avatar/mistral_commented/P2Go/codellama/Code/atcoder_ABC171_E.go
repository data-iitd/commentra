// Importing necessary functions
import "fmt"
import "strconv"

// Reading input
var N int
fmt.Scan(&N)

// Reading input
var a []int
for i := 0; i < N; i++ {
	var ai int
	fmt.Scan(&ai)
	a = append(a, ai)
}

// Calculating the XOR of all elements in the list 'a'
var total int
for _, ai := range a {
	total ^= ai
}

// Printing the result
for _, ai := range a {
	fmt.Printf("%d ", ai^total)
}

// End of code
