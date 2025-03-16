package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		D int
		G int64
		p []int
		c []int
	)

	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &D)
	fmt.Fscan(reader, &G)
	p = make([]int, D)
	c = make([]int, D)
	for i := 0; i < D; i++ {
		fmt.Fscan(reader, &p[i])
		fmt.Fscan(reader, &c[i])
	}

	// Initializing the minimum number of problems solved to a large value
	min := 100000

	// Using bitmask to iterate through all possible combinations of problem completions
	for bit := 0; bit < (1 << D); bit++ {
		score := 0
		solve_num := 0

		// Calculating the total score and the number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if bit&(1<<i)!= 0 {
				score += 100*(i+1)*p[i] + c[i]
				solve_num += p[i]
			}
		}

		// If the score is less than the target, try to maximize the score by completing remaining problems
		if score < G {
			for i := D - 1; i >= 0; i-- {
				if bit&(1<<i) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100*(i+1)
						solve_num++
						if score >= G {
							break
						}
					}
				}
			}
		}

		// Updating the minimum number of problems solved if the current combination meets or exceeds the target score
		if score >= G {
			min = int(min)
			if solve_num < min {
				min = solve_num
			}
		}
	}

	// Output the minimum number of problems solved to achieve the target score
	fmt.Println(min)
}

