package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	arr := make([][]string, n)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		str[i] = scanner.Text()
	}
	for i := 0; i < n; i++ {
		arr[i] = strings.Split(str[i], "")
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
					if arr[i][j] != a {
						res = false
						break
					}
				} else {
					if arr[i][j] != b {
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

