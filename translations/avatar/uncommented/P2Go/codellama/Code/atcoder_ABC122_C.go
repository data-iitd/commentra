package main

import "fmt"

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	s := make([]byte, n)
	fmt.Scan(&s)
	problems := make([][2]int, q)
	for i := range problems {
		fmt.Scan(&problems[i][0], &problems[i][1])
	}
	cumsum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		if s[i-1:i+1] == "AC" {
			cumsum[i] = cumsum[i-1] + 1
		} else {
			cumsum[i] = cumsum[i-1]
		}
	}
	for _, p := range problems {
		fmt.Println(cumsum[p[1]] - cumsum[p[0]-1])
	}
}

