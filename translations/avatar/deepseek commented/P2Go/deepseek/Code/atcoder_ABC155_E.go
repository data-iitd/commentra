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
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	pp := 0
	na := 0
	for i := len(input) - 1; i >= 0; i-- {
		c := input[i]
		cc, _ := strconv.Atoi(string(c))
		cc += na
		na = 0
		if cc <= 4 {
			pp += cc
		} else {
			na = 1
			if i == 0 {
				pp += 1
			} else {
				pp += 10 - cc
			}
		}
	}
	fmt.Println(pp)
}

