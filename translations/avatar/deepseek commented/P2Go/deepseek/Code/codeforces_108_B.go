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
	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)
	// Read a line from the input and discard it
	reader.ReadString('\n')
	// Read another line from the input, split it into a list of strings, convert them to integers, and store it in 'a'
	a := make([]int, 0)
	input, _ := reader.ReadString('\n')
	for _, s := range strings.Split(strings.TrimRight(input, "\n"), " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}
	// Sort the list 'a'
	sort.Ints(a)
	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is not equal to the previous element
		// and if the current element is less than twice the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, print 'YES' and return
			fmt.Println("YES")
			return
		}
	}
	// If the loop completes without finding a match, print 'NO'
	fmt.Println("NO")
}
