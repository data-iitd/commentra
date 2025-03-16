package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	xxs := strings.Split(input, " ")

	x, _ := strconv.Atoi(xxs[0])
	t, _ := strconv.Atoi(xxs[1])
	a, _ := strconv.Atoi(xxs[2])
	b, _ := strconv.Atoi(xxs[3])
	da, _ := strconv.Atoi(xxs[4])
	db, _ := strconv.Atoi(xxs[5])

	if x == 0 {
		fmt.Println("YES")
		return
	}

	aTime := min(a/da, t-1)
	bTime := min(b/db, t-1)

	for i := 0; i <= aTime; i++ {
		for j := 0; j <= bTime; j++ {
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES")
				return
			}
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES")
				return
			}
		}
	}
	fmt.Println("NO")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
