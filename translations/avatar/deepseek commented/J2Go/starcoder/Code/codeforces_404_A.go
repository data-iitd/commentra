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
	fmt.Println("Enter the size of the matrix")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the strings")
	str := make([]string, n)
	for i := 0; i < n; i++ {
		str[i], _ = reader.ReadString('\n')
	}
	arr := make([][]byte, n)
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

