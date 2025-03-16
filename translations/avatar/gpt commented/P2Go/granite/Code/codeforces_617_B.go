
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanln(reader) // Read an input line (not used in further calculations)

	a, _ := reader.ReadString('\n') // Read a string input from the user

	// Check if the string contains any '1's
	// If there are no '1's, print 0
	// Otherwise, calculate the product of counts of '0's between '1's
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		counts := make([]int, 0)
		for _, segment := range strings.Split(strings.Trim(a, "0 "), "1") {
			counts = append(counts, len(segment))
		}
		product := 1
		for _, count := range counts {
			product *= count + 1
		}
		fmt.Println(product)
	}
}
