
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var n int
	sq := make([]int, 10000)
	fr := make([]int, 5000)
	com := make([]int, 0)
	tmp int

	// Start of the infinite loop
	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		// Initialize square array
		for i := 1; i < n; i++ {
			sq[i] = (i * i) % n
		}
		com = make([]int, 0)

		// Find unique squares and store them in the vector
		for i := 1; i < n; i++ {
			f := true
			for j := 0; j < len(com); j++ {
				if com[j] == sq[i] {
					f = false
					break
				}
			}
			if f {
				com = append(com, sq[i])
			}
		}

		// Initialize frequency array
		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		// Find the frequency of each difference between unique squares
		for i := 0; i < len(com); i++ {
			for j := 0; j < len(com); j++ {
				if i!= j {
					tmp = com[i] - com[j]
					if tmp < 0 {
						tmp += n
					}
					if tmp > (n-1)/2 {
						tmp = n - tmp
					}
					fr[tmp]++
				}
			}
		}

		// Print the frequency of each difference
		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

