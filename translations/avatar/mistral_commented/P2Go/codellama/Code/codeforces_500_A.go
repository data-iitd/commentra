// Importing the fmt and strconv packages
import (
	"fmt"
	"strconv"
)

// Taking input for number of test cases and time limit
var n, t int
fmt.Scan(&n, &t)

// Initializing an empty list to store the jumps
var s []int

// Taking input for the jumps
for i := 0; i < n; i++ {
	var jump int
	fmt.Scan(&jump)
	s = append(s, jump)
}

// Initializing the current cell position to 0
currentCell := 0

// Main logic of the program starts here
for currentCell <= t {
	// Incrementing the current cell position by the jump from the previous cell
	currentCell += s[currentCell-1]

	// Checking if the current cell position is equal to the target position
	if currentCell == t {
		// If yes, then print "YES" and exit the program
		fmt.Println("YES")
		return
	}

	// If not, then continue to the next iteration
	continue
}

// If the loop terminates without finding the target position, then print "NO"
fmt.Println("NO")

