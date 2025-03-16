package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n := 0
		fmt.Sscanf(scanner.Text(), "%d", &n)
		a := make([]int, n)
		b := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Sscanf(scanner.Text(), "%d", &a[i])
			b[i] = 0
		}
		s := -1
		tem := 1
		q := 0
		for q != n {
			s++
			if tem == 1 {
				for i := 0; i < n; i++ {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1
					}
				}
				tem = 0
			} else {
				for i := n - 1; i >= 0; i-- {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1
					}
				}
				tem = 1
			}
		}
		fmt.Println(s)
	}
}
