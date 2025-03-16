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
	numbers := strings.Split(input, " ")

	a, _ := strconv.Atoi(numbers[0])
	b, _ := strconv.Atoi(numbers[1])

	c := a - b*2
	if c < 0 {
		c = 0
	}

	fmt.Println(c)
}

