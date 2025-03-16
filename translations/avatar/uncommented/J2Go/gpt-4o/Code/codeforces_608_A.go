package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read n and s
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s, _ := strconv.Atoi(scanner.Text())

	max := 0

	for n > 0 {
		n--

		// Read f and t
		scanner.Scan()
		f, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())

		if max < f+t {
			max = f + t
		}
	}

	fmt.Println(maxInt(max, s))
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
