
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a line of text from the standard input stream and convert it into a list of integers
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	vamshi, z := strings.Split(line, " "), 0
	vamshi, _ = strconv.Atoi(vamshi[0])
	z, _ = strconv.Atoi(vamshi[1])

	// Calculate the number of complete divisions of z into vamshi
	// Add 1 to account for the remainder
	// Multiply the result by z
	fmt.Println((vamshi/z+1)*z)
}

