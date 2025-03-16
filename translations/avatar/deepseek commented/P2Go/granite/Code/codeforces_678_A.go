

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Taking input from the user
	reader := bufio.NewReader(os.Stdin)
	vamshi, _ := reader.ReadString('\n')
	z, _ := reader.ReadString('\n')

	// Converting input to integers
	vamshiInt, _ := strconv.Atoi(vamshi)
	zInt, _ := strconv.Atoi(z)

	// Calculating the result using integer division and addition
	result := (vamshiInt/zInt + 1) * zInt

	// Printing the result
	fmt.Println(result)
}
