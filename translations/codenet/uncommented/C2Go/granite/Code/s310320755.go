
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		n, _ := strconv.Atoi(read(reader))
		if n == 0 {
			break
		}
		flag := true
		r := (n + 1) / 2 + 1
		c := (n + 1) / 2
		arr := make([][]int, n+1)
		for i := 0; i < n+1; i++ {
			arr[i] = make([]int, n+1)
		}
		arr[r][c] = cnt := 1
		for cnt!= n*n+1 {
			cnt++
			if flag {
				r++
				c++
				if c > n {
					c = 1
				}
				if r > n {
					r = 1
				}
				if arr[r][c]!= 0 {
					flag = false
					cnt--
				} else {
					arr[r][c] = cnt
				}
			} else {
				r++
				c--
				if c < 1 {
					c = n
				}
				if r > n {
					r = 1
				}
				if arr[r][c]!= 0 {
					flag = false
				} else {
					arr[r][c] = cnt
					flag = true
				}
			}
		}
		for r = 1; r < n+1; r++ {
			for c = 1; c < n+1; c++ {
				fmt.Printf("%4d", arr[r][c])
				arr[r][c] = 0
				if c == n {
					fmt.Println()
				}
			}
		}
	}
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

