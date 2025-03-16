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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)
	arr := make([]int, t)

	for i := 0; i < len(arr); i++ {
		fmt.Fscan(reader, &arr[i])
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
			if (arr[i]-1)%2 == 0 {
				if prevWinner == 0 {
					fmt.Fprintln(writer, 2)
				} else {
					fmt.Fprintln(writer, 1)
				}
				prevWinner = (prevWinner == 0) ? 2 : 1
			}
		}
	}
}

var prevWinner int = 0
