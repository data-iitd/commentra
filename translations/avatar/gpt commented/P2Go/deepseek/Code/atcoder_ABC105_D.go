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
	values := parseInts(line)
	N, M := values[0], values[1]

	line, _ = reader.ReadString('\n')
	arrStr := parseInts(line)
	A := make([]int64, N)
	for i, v := range arrStr {
		A[i] = int64(v)
	}

	cumRemainders := make([]int64, N+1)
	for i := 1; i <= N; i++ {
		cumRemainders[i] = (cumRemainders[i-1] + A[i-1]) % int64(M)
	}

	remainderCounts := make(map[int64]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}

	combinations := 0
	for _, count := range remainderCounts {
		combinations += count * (count - 1) / 2
	}

	fmt.Println(combinations)
}

func parseInts(line string) []int {
	strs := strings.Split(line, " ")
	ints := make([]int, len(strs))
	for i, str := range strs {
		ints[i], _ = strconv.Atoi(strings.TrimSpace(str))
	}
	return ints
}

