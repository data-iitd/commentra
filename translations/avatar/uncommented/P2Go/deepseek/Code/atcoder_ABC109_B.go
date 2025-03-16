package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1] // Remove newline character
	
	wordCount := make(map[string]int)
	var words []string
	
	for i := 0; i < len(n); i++ {
		word, _ := reader.ReadString('\n')
		word = word[:len(word)-1] // Remove newline character
		words = append(words, word)
		wordCount[word]++
		if wordCount[word] >= 2 {
			fmt.Println("No")
			return
		}
	}
	
	for i := 1; i < len(words); i++ {
		if words[i-1][len(words[i-1])-1] != words[i][0] {
			fmt.Println("No")
			return
		}
	}
	
	fmt.Println("Yes")
}

