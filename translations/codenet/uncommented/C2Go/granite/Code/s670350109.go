
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the first string: ")
	str1, _ := reader.ReadString('\n')
	str1 = strings.TrimSpace(str1)

	fmt.Print("Enter the second string: ")
	str2, _ := reader.ReadString('\n')
	str2 = strings.TrimSpace(str2)

	if len(str1)!= len(str2) {
		fmt.Println("NO")
		return
	}

	temp := reverseString(str1)

	if isAnagram(temp, str2) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}

	count := make(map[rune]int)
	for _, r := range s1 {
		count[r]++
	}
	for _, r := range s2 {
		if count[r] == 0 {
			return false
		}
		count[r]--
	}
	return true
}

// 