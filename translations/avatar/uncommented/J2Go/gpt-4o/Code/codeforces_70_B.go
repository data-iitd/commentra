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
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

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
			idx++
			count = 0
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

// <END-OF-CODE>
