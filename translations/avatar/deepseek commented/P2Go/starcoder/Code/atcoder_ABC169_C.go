
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two inputs, convert one to integer and the other to scaled integer
	sa, sb := bufio.NewReader(os.Stdin).ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(sa))
	b, _ := strconv.Atoi(strings.TrimSpace(sb))

	// Perform the calculation and print the result
	fmt.Printf("%d\n", a*b/100)
}

