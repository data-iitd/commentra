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
	firstline, _ := strconv.Atoi(scanner.Text())

	total := 0
	var memory []string

	for i := 0; i < firstline; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		A, _ := strconv.Atoi(parts[0])
		G, _ := strconv.Atoi(parts[1])

		if total + A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}

	fmt.Println(strings.Join(memory, ""))
}

