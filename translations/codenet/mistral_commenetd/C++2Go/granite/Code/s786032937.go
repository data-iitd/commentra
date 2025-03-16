

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare an integer variable 'n' and read its value from the standard input
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)

	// Output the result, which is calculated as (n - 2) * 180
	fmt.Println((n - 2) * 180)
}

// Indicate successful termination of the program by returning 0
