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
	t, _ := strconv.Atoi(readLine(reader))
	for i := 0; i < t; i++ {
		n, _ := strconv.Atoi(readLine(reader))
		arr := strings.Split(readLine(reader), " ")
		arr = arr[:n]
		prevWinner := 0
		for j := 0; j < n; j++ {
			if arr[j] == "1" {
				if prevWinner == 0 {
					prevWinner = 2
				}
			}
			if prevWinner == 2 || prevWinner == 0 {
				if (arr[j] - 1) % 2 == 0 {
					fmt.Println(2)
					prevWinner = 2
				} else {
					fmt.Println(1)
					prevWinner = 1
				}
			} else {
				if (arr[j] - 1) % 2 == 0 {
					fmt.Println(1)
					prevWinner = 1
				} else {
					fmt.Println(2)
					prevWinner = 2
				}
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

