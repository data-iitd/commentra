package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	var str string
	fmt.Scan(&str)

	t := 0
	for i := 0; i < n; i++ {
		if str[i] != '4' && str[i] != '7' {
			t = 1
			break
		}
	}

	if t == 1 {
		fmt.Println("NO")
	} else {
		x, y := 0, 0
		for i := 0; i < n/2; i++ {
			x += int(str[i] - '0')
		}
		for i := n - 1; i >= n/2; i-- {
			y += int(str[i] - '0')
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
