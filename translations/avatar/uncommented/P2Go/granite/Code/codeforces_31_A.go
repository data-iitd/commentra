
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
	y, _ := strconv.Atoi(readerReadLine(reader))
	arr := make([]int, y)
	for i := 0; i < y; i++ {
		arr[i], _ = strconv.Atoi(readerReadLine(reader))
	}
	for i := 0; i < y; i++ {
		for j := 0; j < y; j++ {
			if i == j {
				continue
			}
			for k := 0; k < y; k++ {
				if arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i]+arr[j] {
					fmt.Printf("%d %d %d\n", k+1, j+1, i+1)
					return
				}
			}
		}
	}
	fmt.Println(-1)
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	panic(err)
}
