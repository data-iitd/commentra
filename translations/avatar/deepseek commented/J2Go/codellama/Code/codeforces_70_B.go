package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	input := make([]byte, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input = append(input, scanner.Bytes()...)
	}

	max := -1
	msgLength := make([]int, len(input)/2)
	count := 0
	idx := 0

	for i := 0; i < len(input); i++ {
		c := input[i]
		if c == '.' || c == '?' || c == '!' {
			msgLength[idx] = count + 1
			if count > max {
				max = count
			}
			i++
			count = 0
			idx++
		} else {
			count++
		}
	}

	if max > n {
		fmt.Println("Impossible")
	} else {
		ans := 0
		for i := 0; i < idx; i++ {
			l := msgLength[i]
			for i < idx-1 && l+msgLength[i+1]+1 <= n {
				l += msgLength[i+1] + 1
				i++
			}
			ans++
		}
		fmt.Println(ans)
	}
}

