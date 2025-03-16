
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input, separated by a space
	reader := bufio.NewReader(os.Stdin)
	vamshiStr, _ := reader.ReadString(' ')
	zStr, _ := reader.ReadString('\n')

	// Convert the strings to integers
	vamshi, _ := strconv.Atoi(vamshiStr)
	z, _ := strconv.Atoi(zStr)

	// Calculate the smallest multiple of z that is greater than or equal to vamshi
	// This is done by performing integer division of vamshi by z, adding 1, and then multiplying by z
	result := (vamshi/z + 1) * z

	// Print the result
	fmt.Println(result)
}
