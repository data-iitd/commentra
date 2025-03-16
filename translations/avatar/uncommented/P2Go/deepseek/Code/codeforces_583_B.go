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
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}

	currentLevel := 0
	counter := 0
	counterTurns := -1
	for counter < len(a) {
		counterTurns++
		for i := 0; i < len(a); i++ {
			if a[i] != -1 && a[i] <= counter {
				counter++
				a[i] = -1
			}
		}
		for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
			a[i], a[j] = a[j], a[i]
		}
	}
	fmt.Println(counterTurns)
}
