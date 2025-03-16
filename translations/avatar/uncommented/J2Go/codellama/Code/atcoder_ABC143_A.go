package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	input = strings.TrimSpace(input)
	inputArray := strings.Split(input, " ")
	a, _ := strconv.Atoi(inputArray[0])
	b, _ := strconv.Atoi(inputArray[1])
	c := a - b*2
	if c < 0 {
		c = 0
	}
	fmt.Println(c)
}

