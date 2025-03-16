
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values a, b, and t from the user
	reader := bufio.NewReader(os.Stdin)
	aStr, _ := reader.ReadString(' ')
	bStr, _ := reader.ReadString(' ')
	tStr, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(aStr)
	b, _ := strconv.Atoi(bStr)
	t, _ := strconv.Atoi(tStr)
	// Initialize cookie counter to 0
	cookie := 0
	// Set initial time to a
	time := a
	// Cookies are produced every 'a' time units, with each production adding 'b' cookies
	// The loop runs as long as the time for production is less than or equal to the total time 't' plus half a time unit
	for time <= t+1 {
		// Increment cookie counter by 'b'
		cookie += b
		// Update time for next production
		time += a
	}
	// Print the total number of cookies produced
	fmt.Println(cookie)
}

