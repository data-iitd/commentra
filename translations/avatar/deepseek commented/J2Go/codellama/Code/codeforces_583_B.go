
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var a []int
	var b []int
	var s int
	var tem int
	var q int

	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			if err == os.EOF {
				break
			}
			fmt.Println(err)
		}

		a = make([]int, n)
		b = make([]int, n)
		s = -1

		for i := 0; i < n; i++ {
			_, err := fmt.Scan(&a[i])
			if err != nil {
				if err == os.EOF {
					break
				}
				fmt.Println(err)
			}
			b[i] = 0
		}

		tem = 1
		q = 0

		for q != n {
			s++

			if tem == 1 {
				for i := 0; i < n; i++ {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1
						q++
					}
				}
				tem = 0
			} else {
				for i := n - 1; i >= 0; i-- {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1
						q++
					}
				}
				tem = 1
			}
		}

		fmt.Println(s)
	}
}

