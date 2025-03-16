package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n := 0
	fmt.Sscanf(nStr, "%d", &n)

	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	words := strings.Split(s, " ")

	// Count occurrences of each word
	wordCount := make(map[string]int)
	for _, word := range words {
		wordCount[word]++
	}

	// Reverse the slice of words
	for i, j := 0, len(words)-1; i < j; i, j = i+1, j-1 {
		words[i], words[j] = words[j], words[i]
	}

	var maxCount int
	var result string
	for word, count := range wordCount {
		if count > maxCount {
			maxCount = count
			result = word
		} else if count == maxCount {
			// Check the last occurrence in the reversed slice
			if lastIndex := indexOf(words, word); lastIndex > indexOf(words, result) {
				result = word
			}
		}
	}

	fmt.Println(result)
}

// Helper function to find the index of a word in a slice
func indexOf(slice []string, word string) int {
	for i, v := range slice {
		if v == word {
			return i
		}
	}
	return -1
}
