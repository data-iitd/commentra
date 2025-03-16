
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func main() {
	n, _ := strconv.Atoi(read())
	s := read()
	if n%2!= 0 {
		fmt.Println("No")
	} else if s[:n/2] == s[n/2:] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func read() string {
	s, _ := reader.ReadString('\n')
	return s[:len(s)-1]
}

