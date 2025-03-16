
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
	input := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&input[i])
	}
	var max int = -1
	msgLength := make([]int, n)
	count := 0
	idx := 0
	for i := 0; i < n; i++ {
		if input[i] == '.' || input[i] == '?' || input[i] == '!' {
			msgLength[idx] = count
			if count > max {
				max = count
			}
			i++
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

