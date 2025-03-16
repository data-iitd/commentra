
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t int
	var arr []int
	var prevWinner int

	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)

	t, _ = strconv.Atoi(scan.Text())
	arr = make([]int, t)

	for i := 0; i < t; i++ {
		arr[i], _ = strconv.Atoi(scan.Text())

		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}

			if (arr[i]-1)%2 == 0 {
				fmt.Println(prevWinner == 0? 2 : 1)
				prevWinner = prevWinner == 0? 2 : 1
			}
		}
	}
}

