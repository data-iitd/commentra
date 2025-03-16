package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read an integer from standard input
func I() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

// Function to read a list of integers from standard input
func LI() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		ints[i] = num
	}
	return ints
}

func main() {
	// Read the number of elements N
	N := I()
	
	// Read the list of integers S, sort them in descending order
	S := LI()
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})
	
	// Initialize a flag array to keep track of used elements
	flag := make([]bool, len(S))
	
	// Initialize the current list with the first element of S
	cur := []int{S[0]}
	
	// Set the flag for the first element to False
	flag[0] = false
	
	// Loop through N times
	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)
		
		// Iterate over the elements of S
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				// Add the element to cur, set its flag to False, and increment j
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}
		
		// If no such element is found, return "No"
		if j == jM {
			fmt.Println("No")
			return
		}
		
		// Sort cur in descending order
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}
	
	// Return "Yes" if the condition is satisfied
	fmt.Println("Yes")
}
