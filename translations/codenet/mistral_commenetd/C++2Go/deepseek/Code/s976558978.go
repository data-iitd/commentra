package main

import (
	"fmt"
	"os"
)

const (
	PI  = 3.141592653589793238462643383279502884197169399375105820974
	ten5p1  = 100001
	ten6p1  = 1000001
	ten8p1  = 100000001
	ten9p1  = 1000000001
)

func readi() int {
	var var int
	fmt.Fscanf(os.Stdin, "%d", &var)
	return var
}

func readll() int64 {
	var var int64
	fmt.Fscanf(os.Stdin, "%d", &var)
	return var
}

func main() {
	a := readi()
	b := readi()

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Printf("%d", a)
		}
		fmt.Println()
	} else {
		for i := 0; i < a; i++ {
			fmt.Printf("%d", b)
		}
		fmt.Println()
	}
}
