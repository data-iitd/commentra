package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, ":")
	h1, _ := strconv.Atoi(parts[0])
	m1, _ := strconv.Atoi(parts[1])
	m1 += h1 * 60

	var input2 string
	fmt.Scanln(&input2)
	parts2 := strings.Split(input2, ":")
	h2, _ := strconv.Atoi(parts2[0])
	m2, _ := strconv.Atoi(parts2[1])
	m2 += h2 * 60

	m2 = m1 - m2
	m2 %= 1440

	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

