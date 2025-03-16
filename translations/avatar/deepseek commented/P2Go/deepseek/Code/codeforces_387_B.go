package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements in round_complexity and george_complexity
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	
	// Read the complexities of the rounds
	roundInput, _ := reader.ReadString('\n')
	roundParts := strings.Split(strings.TrimSpace(roundInput), " ")
	round_complexity := make([]int, n)
	for i := 0; i < n; i++ {
		round_complexity[i], _ = strconv.Atoi(roundParts[i])
	}
	
	// Read the complexities of George's challenges
	georgeInput, _ := reader.ReadString('\n')
	georgeParts := strings.Split(strings.TrimSpace(georgeInput), " ")
	george_complexity := make([]int, m)
	for i := 0; i < m; i++ {
		george_complexity[i], _ = strconv.Atoi(georgeParts[i])
	}
	
	// Initialize counters for both lists
	i, j := 0, 0
	
	// Loop through both lists to compare complexities
	for i < n && j < m {
		if round_complexity[i] <= george_complexity[j] {
			i++
		}
		j++
	}
	
	// Print the number of rounds George can solve
	fmt.Println(n - i)
}
