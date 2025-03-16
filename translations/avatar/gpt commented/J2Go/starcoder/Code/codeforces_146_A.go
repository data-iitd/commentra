package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		return
	}
	// Convert the string to an integer
	n, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		fmt.Println(err)
		return
	}
	// Read the second line of input
	line, err = reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		return
	}
	// Convert the string to an integer
	s, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		fmt.Println(err)
		return
	}
	// Check if the number is lucky
	if s%4 == 0 || s%7 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

