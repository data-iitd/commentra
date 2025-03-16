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
	reader := bufio.NewReader(os.Stdin)
	
	// Read an input line (not used in the logic)
	reader.ReadString('\n')
	
	// Read a line of integers, split by spaces, and convert them to a list of integers
	input, _ := reader.ReadString('\n')
	parts := strings.Fields(input)
	var a []int
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		a = append(a, num)
	}
	
	// Sort the list of integers in ascending order
	sort.Ints(a)
	
	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is different from the previous one
		// and if it is less than double the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			fmt.Println("YES")
			return
		}
	}
	
	// If no such pair is found, return 'NO'
	fmt.Println("NO")
}
