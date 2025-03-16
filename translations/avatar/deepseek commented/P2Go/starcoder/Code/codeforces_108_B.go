
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
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the input, split it into a list of integers, and store it in 'a'
	a := make([]int, 0)
	for {
		input, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		input = strings.TrimSpace(input)
		if input == "" {
			break
		}
		num, err := strconv.Atoi(input)
		if err!= nil {
			break
		}
		a = append(a, num)
	}
	// Sort the list 'a'
	sort.Ints(a)
	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is not equal to the previous element
		// and if the current element is less than twice the previous element
		if a[i]!= a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			fmt.Println("YES")
			return
		}
	}
	// If the loop completes without finding a match, return 'NO'
	fmt.Println("NO")
}

