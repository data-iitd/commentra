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
	fmt.Println("Enter n and m: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	n, _ := strconv.Atoi(strings.Split(input, " ")[0])
	m, _ := strconv.Atoi(strings.Split(input, " ")[1])
	i := 1
	for m >= i {
		m -= i
		i = (i % n) + 1
	}
	fmt.Println(m)
}

