package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	tokens := strings.Fields(input)

	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])
	c, _ := strconv.Atoi(tokens[2])
	d, _ := strconv.Atoi(tokens[3])

	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		values := []int{a, b, c, d}
		sort.Ints(values)
		fmt.Println(values[2] - values[1])
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
