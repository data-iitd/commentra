package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inputs := readLine(reader)
	n, _ := strconv.Atoi(inputs[0])
	L, _ := strconv.Atoi(inputs[1])
	R, _ := strconv.Atoi(inputs[2])
	QL, _ := strconv.Atoi(inputs[3])
	QR, _ := strconv.Atoi(inputs[4])

	W := readLine(reader)
	for i := 0; i < len(W); i++ {
		W[i], _ = strconv.Atoi(W[i])
	}

	// Calculating the prefix sum of the weights
	sum_el := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sum_el[i] = W[i-1] + sum_el[i-1]
	}

	// Initial answer calculation based on the formula
	answer := QR * (n - 1) + sum_el[n] * R

	// Loop to calculate energy for each possible split point
	for i := 1; i <= n; i++ {
		energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i]) // Energy calculation
		if i > (n - i) {                                      // If the left side is heavier
			energy = energy + (i - (n - i) - 1) * QL // Adding QL if needed
		} else if (n - i) > i { // If the right side is heavier
			energy = energy + ((n - i) - i - 1) * QR // Adding QR if needed
		}
		if energy < answer { // Updating the answer if a new minimum energy is found
			answer = energy
		}
	}

	fmt.Println(answer) // Output the minimum energy
}

func readLine(reader *bufio.Reader) []string {
	line, _ := reader.ReadString('\n')
	return strings.Split(strings.TrimRight(line, "\r\n"), " ")
}
