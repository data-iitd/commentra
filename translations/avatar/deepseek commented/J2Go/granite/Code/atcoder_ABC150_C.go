

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Generates all permutations of a given string
func permutation(list []string, target, ans string) []string {
	if len(target) <= 1 {
		list = append(list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			list = permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
	return list
}

func main() {
	// Read the number of strings
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[0])
	// Initialize a 2D array to store the input strings
	line := make([][]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = make([]string, 1)
		// Read n strings and concatenate them
		for j := 0; j < n; j++ {
			line[i][0] += reader.ReadLine()[0]
		}
	}
	// Generate the number string for permutations
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}
	// Create a list to store permutations
	listA := make([]string, 0)
	// Generate all permutations of the number string
	listA = permutation(listA, number, "")
	// Initialize sum to calculate the result
	sum := 0
	// Compare permutations with input strings and calculate the sum
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j][0] {
				if sum == 0 {
					sum += i
				} else {
					sum -= i
				}
			}
		}
	}
	// Print the absolute value of the sum
	fmt.Println(strconv.Itoa(int(math.Abs(float64(sum)))))
}

