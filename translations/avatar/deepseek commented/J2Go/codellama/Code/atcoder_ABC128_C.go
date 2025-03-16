
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of switches (N) and the number of lights (M)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ := strconv.Atoi(sc.Text())

	// Initialize an ArrayList of integers with N elements, all set to 0
	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	// Read M groups of integers, where each group represents a switch and its corresponding states
	for i := 0; i < M; i++ {
		sc.Scan()
		k, _ := strconv.Atoi(sc.Text())
		for j := 0; j < k; j++ {
			sc.Scan()
			s, _ := strconv.Atoi(sc.Text())
			s--
			a[s] |= (1 << i)
		}
	}

	// Read the final state of each light
	p := 0
	for i := 0; i < M; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		p |= (x << i)
	}

	// Calculate the number of possible configurations of switch states that match the final state of the lights
	ans := 0
	for s := 0; s < (1 << N); s++ {
		t := 0
		for i := 0; i < N; i++ {
			if (s>>i)&1 == 1 {
				t ^= a[i]
			}
		}
		if p == t {
			ans++
		}
	}

	// Print the result
	fmt.Println(ans)

	// Close the Scanner object
	sc.Close()
}

