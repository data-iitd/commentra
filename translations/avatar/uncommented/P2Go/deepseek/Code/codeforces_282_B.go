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
	firstline, _ := strconv.Atoi(readLine(reader))
	total := 0
	var memory []string

	for x := 0; x < firstline; x++ {
		line := readLine(reader)
		parts := strings.Split(line, " ")
		A, _ := strconv.Atoi(parts[0])
		G, _ := strconv.Atoi(parts[1])

		if total+A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}

	fmt.Println(strings.Join(memory, ""))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
