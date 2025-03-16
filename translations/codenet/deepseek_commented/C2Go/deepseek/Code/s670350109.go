package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str1, _ := reader.ReadString('\n')
	str2, _ := reader.ReadString('\n')

	str1 = strings.TrimSpace(str1)
	str2 = strings.TrimSpace(str2)

	if len(str1) != len(str2) {
		fmt.Println("NO")
		return
	}

	temp := make([]byte, len(str1))
	j := 0
	t := len(str1) - 1

	for j < len(str1) {
		temp[j] = str1[t]
		j++
		t--
	}

	t = 0
	i := 0
	matchCount := 0

	for i < len(str1) {
		if temp[i] == str2[i] {
			matchCount++
		}
		i++
	}

	if matchCount == len(str2) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

