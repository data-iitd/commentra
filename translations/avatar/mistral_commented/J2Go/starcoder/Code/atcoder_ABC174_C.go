
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring variables for input and output
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Taking the input
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Checking if K is even or multiple of 5, returning -1 if true
	if K%2 == 0 || K%5 == 0 {
		fmt.Fprintln(writer, -1)
		writer.Flush()
		return
	}

	// If K is multiple of 7, dividing it by 7 and multiplying it by 9
	if K%7 == 0 {
		K /= 7
	}
	K *= 9

	// Initializing the answer variable and the remainder variable
	ans := 1
	remainder := 10 % K

	// Using a while loop to find the answer
	for remainder!= 1 {
		ans++ // Incrementing the answer variable
		remainder = remainder * 10 % K // Updating the remainder variable
	}

	// Printing the answer
	fmt.Fprintln(writer, ans)
	writer.Flush()
}

