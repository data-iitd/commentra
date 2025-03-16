
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
		n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		a := make([]int, n)
		b := make([]int, n)
		s := -1
		for i := 0; i < n; i++ {
			a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
			b[i] = 0
		}
		tem := 1
		q := 0
		for q!= n {
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

