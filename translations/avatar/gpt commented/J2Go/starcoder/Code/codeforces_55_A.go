package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a number: ")
	// Read input from stdin
	input, _ := reader.ReadString('\n')
	// Convert input to an integer
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	// Declare variables
	i := 1
	k := 0
	p := 1
	flag := true
	a := make([]int, 1000)
	// Loop through the numbers from 1 to n
	for i = 1; i <= n; i++ {
		// If the number is not in the array, add it
		if a[i] == 0 {
			a[i] = 1
			// If the number is the first occurrence, increment k
			if p == 1 {
				k++
			}
			// If the number is not the first occurrence, set flag to false
			else {
				flag = false
			}
		}
		// If the number is in the array, increment p
		else {
			p++
		}
	}
	// If the number of occurrences is greater than 1, set flag to false
	if k > 1 {
		flag = false
	}
	// If flag is true, print "YES"
	if flag {
		fmt.Println("YES")
	}
	// Otherwise, print "NO"
	else {
		fmt.Println("NO")
	}
}

