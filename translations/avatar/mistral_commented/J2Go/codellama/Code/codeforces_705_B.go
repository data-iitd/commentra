
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
	fmt.Scan(&t)
	arr := make([]int, t)
	for i := 0; i < t; i++ {
		fmt.Scan(&arr[i])
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
			if (arr[i]-1)%2 == 0 {
				fmt.Println(prevWinner == 0 ? 2 : 1)
				prevWinner = (prevWinner == 0 ? 2 : 1)
			}
		}
	}
}

var prevWinner int = 0

