package main

import "fmt"

func main() {
	var pandu, vundu, urdu, c int64
	fmt.Scan(&pandu, &vundu, &urdu)
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}
	if c < vundu {
		fmt.Println("0")
	} else {
		fmt.Println(c - vundu)
	}
}

