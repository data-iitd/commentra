
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values for 'a', 'b', and 't' from the user
	reader := bufio.NewReader(os.Stdin)
	aStr, _ := reader.ReadString(' ')
	bStr, _ := reader.ReadString(' ')
	tStr, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(aStr)
	b, _ := strconv.Atoi(bStr)
	t, _ := strconv.Atoi(tStr)

	// Initialize the cookie count to zero
	cookie := 0

	// Set the initial time to 'a'
	time := a

	// Loop until the time exceeds 't + 0.5'
	for time <= t+0.5 {
		// Add 'b' cookies for each time interval
		cookie += b
		// Increment the time by 'a' for the next iteration
		time += a
	}

	// Print the total number of cookies collected
	fmt.Println(cookie)
}
