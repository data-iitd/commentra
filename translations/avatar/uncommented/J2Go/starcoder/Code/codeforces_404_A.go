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
	fmt.Println("Enter the number of rows: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	arr := make([][]byte, n)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the string: ")
		input, _ = reader.ReadString('\n')
		str[i] = strings.TrimSpace(input)
	}
	for i := 0; i < n; i++ {
		arr[i] = []byte(str[i])
	}
	a := arr[0][0]
	b := arr[0][1]
	if a == b {
		fmt.Println("NO")
	} else {
		res := true
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i == j || i+j == n-1 {
					if arr[i][j]!= a {
						res = false
						break
					}
				} else {
					if arr[i][j]!= b {
						res = false
						break
					}
				}
			}
		}
		if res {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

