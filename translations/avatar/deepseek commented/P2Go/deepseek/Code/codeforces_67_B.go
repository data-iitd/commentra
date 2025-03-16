package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	var n, k int
	fmt.Sscanf(input, "%d %d", &n, &k)

	MInput, _ := reader.ReadString('\n')
	M := []int{}
	for _, s := range strings.Split(MInput, " ") {
		num, _ := strconv.Atoi(s)
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

