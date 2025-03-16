package main

import "fmt"

func main() {
	n, k := 0, 0
	fmt.Scan(&n, &k)
	if n%k == 0 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

