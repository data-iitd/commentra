
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
		fmt.Print("Enter the size of the magic square (0 to exit): ")
		text, _ := reader.ReadString('\n')
		n, _ := strconv.Atoi(text)
		if n == 0 {
			break
		}
		arr := make([][]int, n)
		for i := range arr {
			arr[i] = make([]int, n)
		}
		r, c, cnt := (n+1)/2+1, (n+1)/2, 1
		arr[r-1][c-1] = cnt
		for cnt!= n*n+1 {
			cnt++
			if (r+c)%2 == 1 {
				r++
				c++
				if c > n {
					c = 1
				}
				if r > n {
					r = 1
				}
				if arr[r-1][c-1]!= 0 {
					r--
					c--
					if (r+c)%2 == 1 {
						r--
					} else {
						c++
					}
				}
				arr[r-1][c-1] = cnt
			} else {
				r++
				c--
				if c < 1 {
					c = n
				}
				if r > n {
					r = 1
				}
				if arr[r-1][c-1]!= 0 {
					r--
					c++
					if (r+c)%2 == 1 {
						r--
					} else {
						c++
					}
				}
				arr[r-1][c-1] = cnt
			}
		}
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				fmt.Printf("%4d", arr[i][j])
			}
			fmt.Println()
		}
	}
}

