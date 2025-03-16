
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
	// Read the values of N and A from the standard input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the value of N: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter the value of A: ")
	input, _ = reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(input))

	// Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
	fmt.Println(N%500 <= A)

	// End the main function and return 0 to indicate successful execution
	return
}

