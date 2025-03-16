
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
	fmt.Println("Enter the size of the grid:")
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	fmt.Println("Enter the number of operations:")
	M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	for m := 1; m <= M; m++ {
		fmt.Println("Enter the x-coordinate of the current operation:")
		x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		fmt.Println("Enter the y-coordinate of the current operation:")
		y, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				black[xx][yy]++
				if black[xx][yy] == 9 {
					fmt.Println(m)
					return
				}
			}
		}
	}

	fmt.Println("-1")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

