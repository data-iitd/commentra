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

	vamshi, _ := strconv.Atoi(parts[0])
	z, _ := strconv.Atoi(parts[1])

	// Calculate the number of complete divisions of z into vamshi
	// Add 1 to account for the remainder
	// Multiply the result by z
	result := ((vamshi / z) + 1) * z
	fmt.Println(result)
}

