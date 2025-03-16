package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	main := new(Main)
	main.run()
}

type Main struct{}

func (m *Main) run() {
	// Create a Scanner object to read input from the standard input stream
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of switches (N) and the number of lights (M)
	sc.Scan()
	N := toInt(sc.Text())
	sc.Scan()
	M := toInt(sc.Text())

	// Initialize a slice of integers with N elements, all set to 0
	a := make([]int, N)

	// Read M groups of integers, where each group represents a switch and its corresponding states
	for i := 0; i < M; i++ {
		sc.Scan()
		k := toInt(sc.Text())
		for j := 0; j < k; j++ {
			sc.Scan()
			s := toInt(sc.Text()) - 1
			a[s] |= 1 << i
		}
	}

	// Read the final state of each light
	p := 0
	for i := 0; i < M; i++ {
		sc.Scan()
		x := toInt(sc.Text())
		p |= x << i
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
	sc.Scan() // Consume any remaining input
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

