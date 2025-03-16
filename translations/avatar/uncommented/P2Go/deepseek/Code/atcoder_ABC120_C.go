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
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	if len(s) == 0 {
		return
	}
	
	if len(s) == 1 {
		fmt.Println(0)
		return
	}
	
	freq := make(map[rune]int)
	for _, char := range s {
		freq[char]++
	}
	
	values := make([]int, 0, len(freq))
	for _, count := range freq {
		values = append(values, count)
	}
	
	sort.Ints(values)
	
	ans := values[0] * 2
	fmt.Println(ans)
}
