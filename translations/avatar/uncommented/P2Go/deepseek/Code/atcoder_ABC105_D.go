package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	var N, M int
	fmt.Sscanf(line, "%d %d", &N, &M)

	line, _ = reader.ReadString('\n')
	A := make([]int, N)
	for i, a := range strings.Split(line, " ") {
		A[i], _ = strconv.Atoi(a)
	}

	cum_remainders := make([]int, N+1)
	for i := 0; i < N; i++ {
		cum_remainders[i+1] = (cum_remainders[i] + A[i]) % M
	}

	remainder_counts := make(map[int]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	combinations := 0
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}

	fmt.Println(combinations)
}

