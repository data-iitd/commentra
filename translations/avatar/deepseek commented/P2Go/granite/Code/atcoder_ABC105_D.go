
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of N and M from the standard input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readerReadLine(reader))
	M, _ := strconv.Atoi(readerReadLine(reader))

	// Read the array A from the standard input
	A := readLine(reader)
	A_int64 := make([]int64, N)
	for i := 0; i < N; i++ {
		A_int64[i], _ = strconv.ParseInt(A[i], 10, 64)
	}

	// Calculate the cumulative remainders of the array A modulo M
	// Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
	cum_remainders := make([]int64, N+1)
	cum_remainders[0] = 0
	for i := 0; i < N; i++ {
		cum_remainders[i+1] = (cum_remainders[i] + A_int64[i]) % M
	}

	// Count the occurrences of each remainder
	remainder_counts := make(map[int64]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	// Initialize the number of combinations
	combinations := 0

	// Calculate the number of combinations where the difference between two remainders is a multiple of M
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}

	// Print the number of combinations
	fmt.Println(combinations)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func readLine(reader *bufio.Reader) []string {
	line, _, _ := reader.ReadLine()
	return strings.Split(string(line), " ")
}

