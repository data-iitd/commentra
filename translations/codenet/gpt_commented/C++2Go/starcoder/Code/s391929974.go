package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var sq [10000]int
	var fr [5000]int
	var com []int
	var tmp int

	// Infinite loop to continuously read input until a zero is entered
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}

		// Calculate the squares of numbers from 1 to n-1 modulo n
		for i := 1; i < n; i++ {
			sq[i] = (i * i) % n
		}
		com = com[:0] // Clear the vector for storing unique squares

		// Collect unique square values into the vector 'com'
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

		// Initialize frequency array to count occurrences of differences
		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		// Calculate the frequency of differences between unique squares
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

		// Output the frequency counts for differences from 1 to (n-1)/2
		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

