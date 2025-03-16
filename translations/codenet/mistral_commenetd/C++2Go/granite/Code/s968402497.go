
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	tc, n, m := 0, 0, 0
	fmt.Fscanf(reader, "%d %d %d\n", &tc, &n, &m)
	// Check if 'n' is greater than'm' and swap them if necessary
	if n > m {
		n, m = m, n
	}
	// Iterate through each possible value of 'i' from 1 to'm'
	for i := 1; i <= m; i++ {
		// Check if 'i' multiplied by 'tc' is within the range of 'n' to'm'
		if i*tc >= n && i*tc <= m {
			// If so, print "OK" and set the flag 'fl' to 1
			fmt.Println("OK")
			// Break out of the loop since we have found the answer
			break
		}
	}
	// If the flag 'fl' is still 0, print "NG"
	//fmt.Println("NG")
}

