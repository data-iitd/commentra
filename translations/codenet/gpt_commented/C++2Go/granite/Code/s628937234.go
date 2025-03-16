
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the trailing newline character

	t := string(s[0]) + strconv.Itoa(len(s)-2) + string(s[len(s)-1])

	fmt.Println(t)
}

