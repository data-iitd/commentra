package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read a line of input, split it by spaces, and store it in an array
	scanner.Scan()
	str := strings.Split(scanner.Text(), " ")
	
	// Read the next line of input
	scanner.Scan()
	// Create a new StringTokenizer to read the next line of input
	st := bufio.NewScanner(strings.NewReader(scanner.Text()))
	
	// Parse the first token as an integer and store it in variable 'a'
	st.Scan()
	a, _ := strconv.Atoi(st.Text())
	
	// Parse the second token as an integer and store it in variable 'b'
	st.Scan()
	b, _ := strconv.Atoi(st.Text())
	
	// Read another line of input and store it in variable 'u'
	scanner.Scan()
	u := scanner.Text()
	
	// Compare the string 'u' with the first element of the array 'str'
	// Print the result based on the comparison
	if u == str[0] {
		fmt.Println(fmt.Sprintf("%d %d", a - 1, b))
	} else {
		fmt.Println(fmt.Sprintf("%d %d", a, b - 1))
	}
}
