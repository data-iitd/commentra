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
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	input, _ = reader.ReadString('\n')
	M := []int{}
	for _, numStr := range strings.Split(strings.TrimSpace(input), " ") {
		num, _ := strconv.Atoi(numStr)
		M = append(M, num)
	}

	m := 0
	for j := 0; j < n; j++ {
		for p := 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Printf("%d ", p+1)
				break
			}
		}
		for l := 0; l < p+1-k; l++ {
			M[l] -= 1
		}
		M[p] -= 1
	}
	fmt.Println()
}

