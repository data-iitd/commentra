<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, D int
	var ans, rem int

	// Read two integers from standard input
	N, _ = strconv.Atoi(strings.TrimSpace(os.Args[1]))
	D, _ = strconv.Atoi(strings.TrimSpace(os.Args[2]))

	// Calculate the number of groups that can be formed
	ans = N / (D*2+1)
	rem = N % (D*2+1)

	// If there are remaining items, increment the number of groups
	if rem!= 0 {
		ans = ans + 1
	}

	// Print the result to standard output
	fmt.Printf("%d\n", ans)
}

