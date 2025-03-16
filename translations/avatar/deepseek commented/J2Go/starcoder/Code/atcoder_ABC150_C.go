
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of strings
	var n int
	fmt.Scanf("%d", &n)
	// Initialize a 2D array to store the input strings
	var line [2][1]string
	for i := 0; i < 2; i++ {
		for j := 0; j < 1; j++ {
			line[i][j] = ""
		}
	}
	// Read n strings and concatenate them
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &line[0][0])
		line[0][0] += line[0][0]
	}
	// Generate the number string for permutations
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}
	// Create a list to store permutations
	listA := make([]string, 0)
	// Generate all permutations of the number string
	permutation(number, "", &listA)
	// Initialize sum to calculate the result
	sum := 0
	// Compare permutations with input strings and calculate the sum
	for j := 0; j < 2; j++ {
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
	fmt.Printf("%d\n", sum)
}

// Generates all permutations of a given string
func permutation(target string, ans string, listA *[]string) {
	if len(target) <= 1 {
		*listA = append(*listA, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			permutation(target[0:i]+target[i+1:], ans+target[i], listA)
		}
	}
}

