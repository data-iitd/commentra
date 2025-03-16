
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	cnt4 := 0
	cnt2 := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		wk, _ := strconv.Atoi(scanner.Text())
		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}

	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

