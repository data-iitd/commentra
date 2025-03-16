
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the standard input stream
	in := bufio.NewScanner(os.Stdin)

	// Read a line of input, split it by spaces, and store it in an array
	in.Scan()
	str := strings.Split(in.Text(), " ")

	// Read a line of input and split it by spaces, storing the tokens in variables 'a' and 'b'
	in.Scan()
	tokens := strings.Split(in.Text(), " ")
	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])

	// Read another line of input and store it in variable 'u'
	in.Scan()
	u := in.Text()

	// Compare the string 'u' with the first element of the array'str'
	// Print the result based on the comparison
	if u == str[0] {
		fmt.Println((a - 1), b)
	} else {
		fmt.Println(a, (b - 1))
	}
}

