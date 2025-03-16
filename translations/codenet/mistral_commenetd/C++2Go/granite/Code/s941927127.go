

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a word: ")
	text, _ := reader.ReadString('\n')
	word := strings.TrimSpace(text)
	runes := []rune(word)
	sort.Runes(runes)
	sortedWord := string(runes)
	isAnagram := true
	for i := 0; i < len(sortedWord)-1; i++ {
		if sortedWord[i]!= sortedWord[i+1] {
			isAnagram = false
			break
		}
	}
	if isAnagram {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

