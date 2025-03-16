
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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	nTemp, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nTemp))
	fmt.Println("Enter the elements separated by spaces:")
	sTemp, _ := reader.ReadString('\n')
	s := strings.Split(strings.TrimSpace(sTemp), " ")
	m := make(map[string]int)
	for _, v := range s {
		m[v]++
	}
	maxCount := 0
	maxCountKey := ""
	for k, v := range m {
		if v > maxCount {
			maxCount = v
			maxCountKey = k
		}
	}
	lastIndex := -1
	for i, v := range s {
		if v == maxCountKey {
			lastIndex = i
		}
	}
	fmt.Println(maxCountKey)
}

