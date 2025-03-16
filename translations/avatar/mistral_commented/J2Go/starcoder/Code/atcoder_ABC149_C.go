// Importing necessary libraries
import (
	"fmt"
	"math"
	"os"
	"strconv"
)

// Main method is the entry point of the Go application
func main() {
	// Reading an integer input from the user
	x, _ := strconv.Atoi(os.Stdin.ReadString('\n'))

	// Checking if the number is even and not equal to 2
	if x!= 2 && x%2 == 0 {
		x++
	}

	// Starting an infinite loop
	for {
		i := 3
		sqrtNum := math.Sqrt(float64(x))

		// Checking for prime numbers using trial division method
		for i <= int(sqrtNum) {
			if x%i == 0 {
				break
			}
			i += 2
		}

		// If 'i' is greater than the square root, then the number 'x' is prime
		if i > int(sqrtNum) {
			break
		}

		// If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
		x += 2
	}

	// Printing the prime number found
	fmt.Println(x)
}

