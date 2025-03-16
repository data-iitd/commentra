
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input which represents the number of elements
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(nTemp, 10, 64)
	checkError(err)

	// Read a line of input, split it into individual strings, convert them to integers, and store them in a list
	rTemp, err := reader.ReadString('\n')
	checkError(err)
	rTemp = rTemp[:len(rTemp)-1]
	r := make([]int64, n)
	for i, rTempI := range strings.Split(rTemp, " ") {
		rI, err := strconv.ParseInt(rTempI, 10, 64)
		checkError(err)
		r[i] = rI
	}

	// Initialize the answer with the absolute value of the first element in the list
	ans := int64(0)
	ans += int64(math.Abs(float64(r[0])))

	// Iterate through the list starting from the second element
	for i := 1; i < int(n); i++ {
		// Add the absolute difference between the current element and the previous element to the answer
		ans += int64(math.Abs(float64(r[i] - r[i-1])))
	}

	// Print the final computed answer
	fmt.Println(ans)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

