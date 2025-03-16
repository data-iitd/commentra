

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(text)

	l := 1
	r := n

	for l < r {
		mid := l + (r-l)/2
		idxcnt := mid * (mid + 1) / 2

		if idxcnt < n {
			l = mid + 1
		} else {
			r = mid
		}
	}

	l -= 1
	idxcnt := l * (l + 1) / 2

	fmt.Println(n - idxcnt)
}

