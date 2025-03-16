

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
	fmt.Println("First string:", str1)

	fmt.Print("Enter the second string: ")
	str2, _ := reader.ReadString('\n')
	str2 = strings.TrimSpace(str2)
	fmt.Println("Second string:", str2)

	if len(str1)!= len(str2) {
		fmt.Println("NO")
		return
	}

	temp := reverseString(str1)
	if temp == str2 {
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

