<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
<<<<<<< HEAD
	// Declare variables n, k, and cnt of type int
	var n, k, cnt int

	// Read two integers n and k from the standard input using fmt.Scan()
	fmt.Scan(&n, &k)
	// Initialize variable cnt to zero
	cnt = 0
	// Loop through n times using a for loop
	for n > 0 {
		// Declare variable h of type int
		var h int

		// Read an integer h from the standard input using fmt.Scan()
		fmt.Scan(&h)
		// If h is greater than or equal to k, increment cnt by 1
		if h >= k {
			cnt++
		}
		// Decrement n by 1
		n--
	}
	// Print the value of cnt to the standard output using fmt.Println()
=======
	n, _ := strconv.Atoi(os.Args[1])
	k, _ := strconv.Atoi(os.Args[2])
	cnt := 0
	for n > 0 {
		h, _ := strconv.Atoi(os.Args[n])
		if h >= k {
			cnt++
		}
		n--
	}
>>>>>>> 98c87cb78a (data updated)
	fmt.Println(cnt)
}

