package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inputs := readTwoInts(reader)
	N := inputs[0]
	M := inputs[1]

	A := readInts(reader)

	cumRemainders := make([]int, N+1)
	for i := 0; i < N; i++ {
		cumRemainders[i+1] = (cumRemainders[i] + A[i]) % M
	}

	remainderCounts := make(map[int]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}

	combinations := 0
	for _, count := range remainderCounts {
		combinations += count * (count - 1) / 2
	}

	fmt.Println(combinations)
}

func readTwoInts(reader *bufio.Reader) []int {
	input, _ := reader.ReadString('\n')
	parts := splitString(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func readInts(reader *bufio.Reader) []int {
	input, _ := reader.ReadString('\n')
	parts := splitString(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func splitString(input string) []string {
	var parts []string
	var part string
	for _, char := range input {
		if char == ' ' || char == '\n' {
			if len(part) > 0 {
				parts = append(parts, part)
				part = ""
			}
		} else {
			part += string(char)
		}
	}
	if len(part) > 0 {
		parts = append(parts, part)
	}
	return parts
}
