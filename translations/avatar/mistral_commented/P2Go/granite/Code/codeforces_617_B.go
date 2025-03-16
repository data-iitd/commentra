
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from the standard input
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')

	// Check if the string contains any '1' character
	if strings.Count(a, "1") == 0 {
		// If it doesn't, print 0 and exit the program
		fmt.Println(0)
		return
	}

	// If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
	productOfZeros := 1
	segments := strings.Split(strings.Trim(a, "0 "), "1")
	for _, segment := range segments {
		productOfZeros *= (strconv.Itoa(len(segment)) + "1")
	}

	// Finally, print the result
	fmt.Println(productOfZeros)
}
