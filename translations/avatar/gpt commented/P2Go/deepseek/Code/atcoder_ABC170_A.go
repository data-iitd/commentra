package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")

	var a []int
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		a = append(a, num)
	}

	for e, i := range a {
		if i == 0 {
			fmt.Println(e + 1)
			break
		}
	}
}

