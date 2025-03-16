package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	if n < 4 {
		fmt.Println("No")
		return
	}

	flg := false

	for i := 0; i <= n/4; i++ {
		for j := 0; j <= n/7; j++ {
			if i*4+j*7 == n {
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

