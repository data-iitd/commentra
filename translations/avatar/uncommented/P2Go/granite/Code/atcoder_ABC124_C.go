
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	even := make(map[string]int)
	odd := make(map[string]int)
	for i, v := range s {
		if i%2 == 0 {
			even[string(v)]++
		} else {
			odd[string(v)]++
		}
	}
	fmt.Println(min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

