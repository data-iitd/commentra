
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	b, _ := reader.ReadString('\n')

	aInt, _ := strconv.ParseUint(a, 10, 32)
	bInt, _ := strconv.ParseUint(b, 10, 32)

	fmt.Printf("%032b\n", aInt&bInt) // Print the binary AND of a and b
	fmt.Printf("%032b\n", aInt|bInt) // Print the binary OR of a and b
	fmt.Printf("%032b\n", aInt^bInt) // Print the binary XOR of a and b

	// 