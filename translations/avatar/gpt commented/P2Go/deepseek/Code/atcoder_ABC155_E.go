package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func main() {
	// Read input string
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	pp := 0
	na := 0

	// Process the string in reverse order
	for i := len(input) - 1; i >= 0; i-- {
		c := input[i]
		cc := na + int(c - '0')
		na = 0

		if cc <= 4 {
			pp += cc
		} else {
			na = 1
			pp += 10 - cc
			if i == 0 {
				pp++
			}
		}
	}

	fmt.Println(pp)
}

