package main

import "fmt"

func main() {
	var a, b, c, d int
	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)
	fmt.Println(max(a*c, b*d, a*d, b*c))
}

func max(a, b, c, d int) int {
	if a > b {
		if a > c {
			if a > d {
				return a
			}
			return d
		}
		if c > d {
			return c
		}
		return d
	}
	if b > c {
		if b > d {
			return b
		}
		return d
	}
	if c > d {
		return c
	}
	return d
}

// 