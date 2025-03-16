package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')

	max, cnt := 0, 0

	for _, sc := range str {
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			cnt++
		} else {
			cnt = 0
		}
		if max < cnt {
			max = cnt
		}
	}

	fmt.Println(max)
}

