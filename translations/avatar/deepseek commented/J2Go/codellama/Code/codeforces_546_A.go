package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var pandu, vundu, urdu, c int64
	var err error

	if len(os.Args) != 4 {
		fmt.Println("Usage: please provide three integer inputs")
		os.Exit(1)
	}

	pandu, err = strconv.ParseInt(os.Args[1], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}

	vundu, err = strconv.ParseInt(os.Args[2], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}

	urdu, err = strconv.ParseInt(os.Args[3], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}

	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	if c < vundu {
		fmt.Println("0")
	} else {
		fmt.Println(c - vundu)
	}
}

