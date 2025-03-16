package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
	if n%k == 0 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

