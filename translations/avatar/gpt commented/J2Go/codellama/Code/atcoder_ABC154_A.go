package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a bufio.Scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input and store it in variable 'str'
	scanner.Scan()
	str := scanner.Text()

	// Create a bufio.Scanner to read the next line of input
	scanner.Scan()

	// Parse the first token as an integer and store it in variable 'a'
	a, _ := strconv.Atoi(strings.Split(scanner.Text(), " ")[0])

	// Parse the second token as an integer and store it in variable 'b'
	b, _ := strconv.Atoi(strings.Split(scanner.Text(), " ")[1])

	// Read another line of input and store it in variable 'u'
	scanner.Scan()
	u := scanner.Text()

	// Compare the string 'u' with the first element of the array 'str'
	// Print the result based on the comparison
	fmt.Println(u, str[0])
	if u == str[0] {
		fmt.Println(a-1, b)
	} else {
		fmt.Println(a, b-1)
	}
}

