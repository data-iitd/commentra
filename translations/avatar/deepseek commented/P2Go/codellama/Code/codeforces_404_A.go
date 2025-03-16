
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	flag := 0
	d1 := make([]string, n)
	d2 := make([]string, n)
	rem := make(map[string]int)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				d1[i] = s[i][j]
			}
			if i == n-j-1 {
				d2[i] = s[i][j]
			}
			if i != j && i != n-j-1 {
				rem[s[i][j]]++
			}
		}
	}

	if len(rem) != 1 {
		fmt.Println("NO")
	} else if d1 != d2 {
		fmt.Println("NO")
	} else if len(rem) != 1 {
		fmt.Println("NO")
	} else if rem == d1 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

