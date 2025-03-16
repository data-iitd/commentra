package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove newline character
	charArray := []rune(input)
	
	mapa := make(map[rune]int)
	for _, char := range charArray {
		if _, exists := mapa[char]; !exists {
			mapa[char] = 1
		} else {
			mapa[char]++
		}
	}
	
	ok := true
	for _, value := range mapa {
		if value != 2 {
			ok = false
			break
		}
	}
	
	if ok && len(mapa) == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

