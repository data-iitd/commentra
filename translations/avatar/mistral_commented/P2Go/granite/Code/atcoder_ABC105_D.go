
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input number of rows and columns
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	N, M := parseLine(line)

	// Initialize slice 'A' with given dimensions and data type
	A := make([]int64, N)
	line, _, _ = reader.ReadLine()
	A = parseLine(line)

	// Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
	cum_remainders := make([]int64, N)
	cum_remainders[0] = A[0] % M
	for i := 1; i < N; i++ {
		cum_remainders[i] = (cum_remainders[i-1] + A[i]) % M
	}

	// Count the occurrences of each cumulative remainder
	remainder_counts := make(map[int64]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}

	// Calculate the number of combinations of elements having the same remainder
	combinations := int64(0)
	for _, count := range remainder_counts {
		combinations += int64(count) * (int64(count) - 1) / 2
	}

	// Print the result
	fmt.Println(combinations)
}

func parseLine(line []byte) []int64 {
	tokens := bytes.Split(line, []byte{' '})
	A := make([]int64, len(tokens))
	for i, token := range tokens {
		A[i], _ = strconv.ParseInt(string(token), 10, 64)
	}
	return A
}

