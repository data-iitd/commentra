package main

import (
	"bufio"
	"fmt"
	"os"
)

const INF = 100000

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	D := readInt(scanner)
	G := readLong(scanner)
	p := make([]int, D)
	c := make([]int, D)

	// Reading the number of problems completed and the bonus points for each problem
	for i := 0; i < D; i++ {
		p[i] = readInt(scanner)
		c[i] = readInt(scanner)
	}

	min := INF // Initializing the minimum number of problems solved to a large value

	// Using bitmask to iterate through all possible combinations of problem completions
	for bit := 0; bit < (1 << D); bit++ {
		score := 0 // Initializing the current score
		solveNum := 0 // Initializing the number of problems solved

		// Calculating the total score and the number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if bit&(1<<i) != 0 {
				score += 100 * (i + 1) * p[i] + c[i]
				solveNum += p[i]
			}
		}

		// If the score is less than the target, try to maximize the score by completing remaining problems
		if score < G {
			for i := D - 1; i >= 0; i-- {
				if bit&(1<<i) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * (i + 1)
						solveNum++
						if score >= G {
							break
						}
					}
				}
			}
		}

		// Updating the minimum number of problems solved if the current combination meets or exceeds the target score
		if score >= G {
			if solveNum < min {
				min = solveNum
			}
		}
	}

	// Output the minimum number of problems solved to achieve the target score
	fmt.Println(min)
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}
