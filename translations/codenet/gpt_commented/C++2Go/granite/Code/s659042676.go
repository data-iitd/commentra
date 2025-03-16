
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the first integer: ")
	a, _ := reader.ReadString('\n')
	a, _ = strconv.Atoi(a)

	fmt.Print("Enter the second integer: ")
	b, _ := reader.ReadString('\n')
	b, _ = strconv.Atoi(b)

	result := 6 - a - b
	fmt.Println("Result:", result)
}

