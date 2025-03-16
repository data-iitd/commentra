package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, L, R, QL, QR int
	fmt.Fscan(reader, &n, &L, &R, &QL, &QR)

	var W = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &W[i])
	}

	var sum_el = make([]int, n+1)
	sum_el[0] = 0

	for i := 1; i <= n; i++ {
		sum_el[i] = W[i-1] + sum_el[i-1]
	}

	var answer = QR * (n - 1) + sum_el[n] * R

	for i := 1; i <= n; i++ {
		var energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i])

		if i > (n - i) {
			energy += (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			energy += ( (n - i) - i - 1) * QR
		}

		if energy < answer {
			answer = energy
		}
	}

	fmt.Fprintln(writer, answer)
}

