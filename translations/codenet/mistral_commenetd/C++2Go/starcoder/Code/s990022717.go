<<<<<<< HEAD
import "fmt"

func main() {
	// Initialize variables
	var n, k, x, y int
	fmt.Scanf("%d %d %d %d", &n, &k, &x, &y) // Read input values for n, k, x, and y from standard input

	sum := 0 // Initialize sum variable to 0

	// Iterate through numbers from 1 to n
	for i := 1; i <= n; i++ {
		// If the current number i is greater than k, add y to the sum
		if i > k {
			sum += y
		} else {
			sum += x
		}
	}

	// Output the final sum value to the standard output
	fmt.Println(sum)
=======
package main
import "fmt"

func main() {
    var n, k, x, y int
    fmt.Scanf("%d %d %d %d", &n, &k, &x, &y)
    sum := 0
    for i := 1; i <= n; i++ {
        if i > k {
            sum += y
        } else {
            sum += x
        }
    }
    fmt.Println(sum)
>>>>>>> 98c87cb78a (data updated)
}

