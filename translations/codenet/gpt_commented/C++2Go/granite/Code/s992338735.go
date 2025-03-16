
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Continuously read input until a non-positive integer is entered
	for {
		N, err := readInt()
		if err!= nil || N <= 0 {
			break
		}

		M, m, addup, i := -1, 1001, 0, 0
		// Loop to read N integers
		for i = 0; i < N; i++ {
			S, err := readInt()
			if err!= nil {
				break
			}

			addup += S
			// Update the maximum value if the current integer is greater
			if S > M {
				M = S
			}
			// Update the minimum value if the current integer is smaller
			if S < m {
				m = S
			}
		}

		// Calculate the average excluding the maximum and minimum values
		// and print the result
		fmt.Println((addup - M - m) / (N - 2))
	}
}

func readInt() (int, error) {
	var (
		n    int
		err  error
		read int
	)
	buf := make([]byte, 1024)
	for {
		read, err = os.Stdin.Read(buf)
		if err!= nil {
			return 0, err
		}
		n, err = strconv.Atoi(string(buf[:read]))
		if err == nil {
			return n, nil
		}
	}
}

