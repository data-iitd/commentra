package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(os.Args[1])
	R, _ := strconv.Atoi(os.Args[2])

	if N >= 10 {
		fmt.Printf("%d\n", R)
	} else {
		fmt.Printf("%d\n", R+100*(10-N))
	}
}

