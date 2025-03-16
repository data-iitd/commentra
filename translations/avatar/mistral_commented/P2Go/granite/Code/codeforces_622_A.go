
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the sequence:")
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	idxcnt := 0
	l := 1
	r, _ := strconv.Atoi(n)
	for l < r {
		mid := l + (r-l)/2
		idxcnt = mid * (mid + 1) / 2
		if idxcnt < r {
			l = mid + 1
		} else {
			r = mid
		}
	}
	l--
	idxcnt = l * (l + 1) / 2
	fmt.Println(r - idxcnt)
}

