package main

import (
	"fmt"
)

func main() {
	var n uint64
	fmt.Scan(&n)
	flg := false
	if n < 4 {
		fmt.Println("No")
	} else {
		for i := uint64(0); i <= (n / 4); i++ {
			for j := uint64(0); j <= (n / 7); j++ {
				if (i*4+j*7) == n {
					flg = true
					break
				}
			}
			if flg {
				break
			}
		}
		if flg {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

