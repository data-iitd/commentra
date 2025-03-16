
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the value of N from the standard input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the value of N: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))

	// Read the value of A from the standard input
	fmt.Print("Enter the value of A: ")
	input, _ = reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(input))

	// Calculate the result and print it to the standard output
	fmt.Println(N*N - A)
}

