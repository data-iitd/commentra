
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// The code reads an integer N.
	N := readInt()

	// It then creates a list A where each element is the product of an integer input and N plus its index i, for i in range(N).
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt()*N + i
	}

	// The list A is sorted.
	sort.Ints(A)

	// A counter cnt is initialized to 0.
	cnt := 0

	// The code then iterates over the elements of A, checking if the remainder when divided by N, when divided by 2, matches the remainder of the index i when divided by 2.
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2!= i%2 {
			cnt++
		}
	}

	// If they do not match, the counter cnt is incremented.

	// Finally, the code prints the result of cnt divided by 2.
	fmt.Println(cnt / 2)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

