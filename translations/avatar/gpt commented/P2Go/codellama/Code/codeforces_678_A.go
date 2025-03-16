package main

import "fmt"

func main() {
	var vamshi, z int
	fmt.Scan(&vamshi, &z)
	result := (vamshi/z + 1) * z
	fmt.Println(result)
}

