
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
	var input string
	fmt.Scan(&input)

	var max int = -1
	var msgLength []int = make([]int, len(input)/2)
	var count int = 0
	var idx int = 0

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
		return
	}

	var ans int = 0

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

