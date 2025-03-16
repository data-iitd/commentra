
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	charMap := make(map[string]int)
	oddCount := 0
	for _, char := range str {
		charStr := string(char)
		if _, ok := charMap[charStr]; ok {
			charMap[charStr]++
		} else {
			charMap[charStr] = 1
		}
	}
	for _, count := range charMap {
		if count%2!= 0 {
			oddCount++
		}
	}
	if oddCount <= 1 || oddCount%2!= 0 {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}

// 