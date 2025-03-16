
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Step 1: Take an integer input N, which represents the number of elements in the list.
	N, _ := strconv.Atoi(read(reader))

	// Step 2: Take a list of integers as input and store them in the list 'a'.
	a := readN(reader, N)

	// Step 3: Calculate the total XOR of all elements in the list 'a' using reduce and XOR operator.
	total := reduce(xor, a, 0)

	// Step 4: Create a new list where each element is the XOR of the original element and the total.
	// Print the new list as a space-separated string.
	fmt.Println(join(map(lambda ai: str(ai ^ total), a)))
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	return s
}

func readN(reader *bufio.Reader, n int) []int {
	s := read(reader)
	s = s[:len(s)-1]
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(s[i*2 : i*2+2])
	}
	return a
}

func join(a []string) string {
	s := ""
	for _, e := range a {
		s += e + " "
	}
	return s
}

func reduce(f func(int, int) int, a []int, init int) int {
	r := init
	for _, e := range a {
		r = f(r, e)
	}
	return r
}

func xor(a, b int) int {
	return a ^ b
}

