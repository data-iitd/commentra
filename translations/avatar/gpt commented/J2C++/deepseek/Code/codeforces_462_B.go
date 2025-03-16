package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type c462b struct {
	left int
}

func (c c462b) String() string {
	return fmt.Sprintf("c462b{left: %d}", c.left)
}

func main() {
	// Initialize BufferedReader to read input from standard input
	reader := bufio.NewReader(os.Stdin)
	
	// Initialize PrintWriter to output results to standard output
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	
	// Read the first line of input and tokenize it to extract n and k
	input, _ := reader.ReadString('\n')
	st := strings.Fields(input)
	n, _ := strconv.Atoi(st[0]) // Number of cards
	k, _ := strconv.Atoi(st[1]) // Maximum number of changes allowed
	
	// Create an array of c462b objects to count occurrences of each letter
	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{left: 0} // Initialize each card
	}
	
	// Read the string of cards and count the occurrences of each letter
	input, _ = reader.ReadString('\n')
	for _, char := range input {
		if char >= 'A' && char <= 'Z' {
			cards[char - 'A'].left++ // Increment the count for the corresponding letter
		}
	}
	
	ans := int64(0) // Variable to store the final answer
	
	// Perform k operations to maximize the score
	for i := 0; i < k; i++ {
		// Sort the cards based on the count of letters
		sort.Slice(cards, func(i, j int) bool {
			return cards[i].left < cards[j].left
		})
		
		// Determine the number of changes to make for the most frequent letter
		change := int64(min(cards[25].left, int(k - i)))
		ans += change * change // Update the answer with the square of changes
		
		// Decrease the count of the most frequent letter by the number of changes made
		cards[25].left -= int(change)
		i += int(change) - 1 // Adjust the loop counter based on changes made
	}
	
	// Output the final result
	fmt.Fprintln(out, ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

